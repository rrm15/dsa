#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
  string title;
  double duration; // in seconds

public:
  Media(string t, double d) : title(t), duration(d) {}

  virtual void play() {
    cout << "Playing media: " << title << " (" << duration << "s)" << endl;
  }

  virtual ~Media() {}
};

class Audio : public Media {
  string artist;

public:
  Audio(string t, double d, string a) : Media(t, d), artist(a) {}

  void play() override {
    cout << "♪ Playing audio: \"" << title << "\" by " << artist << " ["
         << duration << "s]" << endl;
  }
};

class Video : public Media {
  string resolution;

public:
  Video(string t, double d, string r) : Media(t, d), resolution(r) {}

  void play() override {
    cout << "▶ Playing video: \"" << title << "\" [" << resolution << ", "
         << duration << "s]" << endl;
  }
};

int main() {
  Audio song("Bohemian Rhapsody", 354.0, "Queen");
  Video clip("Nature Documentary", 1800.0, "4K");

  cout << "--- Direct calls ---" << endl;
  song.play();
  clip.play();

  // polymorphism via base class pointer
  cout << "\n--- Polymorphism via Media* ---" << endl;
  Media *playlist[] = {&song, &clip};
  for (int i = 0; i < 2; i++)
    playlist[i]->play();

  return 0;
}
