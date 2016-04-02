/*
We have a MediaPlayer interface and a concrete class AudioPlayer implementing
the MediaPlayer interface.AudioPlayer can play mp3 format audio files by
default.

We are having another interface AdvancedMediaPlayer and concrete classes
implementing the AdvancedMediaPlayer interface.These classes can play vlc and
mp4 format files.

We want to make AudioPlayer to play other formats as well.To attain this, we
have created an adapter class MediaAdapter which implements the
MediaPlayer interface and uses AdvancedMediaPlayer objects to play the required
format.

AudioPlayer uses the adapter class MediaAdapter passing it the desired audio
type without knowing the actual class which can play the desired format.
*/

#include <iostream>

class MediaPlayer {
 public:
  virtual void play(std::string audio_type, std::string file_name) = 0;
};

class AdvancedMediaPlayer {
 public:
  virtual void playVlc(std::string file_name) = 0;
  virtual void playMp4(std::string file_name) = 0;
};

class VlcMediaPlayer : public AdvancedMediaPlayer {
 public:
  void playVlc(std::string file_name) override {
    std::cout << "Playing via VLC player \n";
  }

  void playMp4(std::string file_name) override {}
};

class Mp4MediaPlayer : public AdvancedMediaPlayer {
 public:
  void playVlc(std::string file_name) override {}

  void playMp4(std::string file_name) override {
    std::cout << "Playing via MP4 player \n";
  }
};

class MediaAdaptor : public MediaPlayer {
 public:
  MediaAdaptor(std::string audio_type) {
    if (audio_type.find("vlc") != std::string::npos) {
      adv_player_ = new VlcMediaPlayer();
    } else if (audio_type.find("mp4") != std::string::npos) {
      adv_player_ = new Mp4MediaPlayer();
    }
  }

  void play(std::string audio_type, std::string file_name) {
    if (audio_type.find("vlc") != std::string::npos) {
      adv_player_->playVlc(file_name);
    } else if (audio_type.find("mp4") != std::string::npos) {
      adv_player_->playMp4(file_name);
    }
  }

 private:
  AdvancedMediaPlayer* adv_player_;
};

class AudioPlayer : public MediaPlayer {
 public:
  void play(std::string audio_type, std::string file_name) {
    if (audio_type.find("mp3") != std::string::npos) {
      std::cout << "Playing via AudioPlayer \n";
    } else if (audio_type.find("vlc") != std::string::npos ||
               audio_type.find("mp4") != std::string::npos) {
      media_adaptor_ = new MediaAdaptor(audio_type);
      media_adaptor_->play(audio_type, file_name);
    } else {
      std::cout << "format not support \n";
    }
  }

 private:
  MediaAdaptor* media_adaptor_;
};

int main(int argc, char const* argv[]) {
  AudioPlayer player;

  player.play("mp3", "beyond the horizon.mp3");
  player.play("mp4", "alone.mp4");
  player.play("vlc", "far far away.vlc");
  player.play("avi", "mind me.avi");
  return 0;
}