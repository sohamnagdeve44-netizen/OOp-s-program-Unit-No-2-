#include <iostream>      // Provides cout and endl
#include <vector>        // Provides vector
#include <memory>        // Provides unique_ptr and make_unique

using namespace std;

// Base class
class Media {
public:

    // Pure virtual functions
    // These functions must be implemented by derived classes
    virtual void play() const = 0;
    virtual void pause() const = 0;
    virtual void stop() const = 0;
    virtual void showDetails() const = 0;

    // Virtual destructor for proper cleanup
    virtual ~Media() = default;
};


// Derived class Audio
class Audio : public Media {
private:
    string title;        // Stores audio title
    string artist;       // Stores artist name

public:

    // Constructor
    Audio(string t, string a)
        : title(t), artist(a) {}

    // Implements play()
    void play() const override {
        cout << "Playing audio: " << title << endl;
    }

    // Implements pause()
    void pause() const override {
        cout << "Pausing audio: " << title << endl;
    }

    // Implements stop()
    void stop() const override {
        cout << "Stopping audio: " << title << endl;
    }

    // Displays audio details
    void showDetails() const override {
        cout << "Audio: " << title
             << " | Artist: " << artist << endl;
    }
};


// Derived class Video
class Video : public Media {
private:
    string title;        // Stores video title
    string resolution;   // Stores video resolution

public:

    // Constructor
    Video(string t, string r)
        : title(t), resolution(r) {}

    // Implements play()
    void play() const override {
        cout << "Playing video: " << title << endl;
    }

    // Implements pause()
    void pause() const override {
        cout << "Pausing video: " << title << endl;
    }

    // Implements stop()
    void stop() const override {
        cout << "Stopping video: " << title << endl;
    }

    // Displays video details
    void showDetails() const override {
        cout << "Video: " << title
             << " | Resolution: " << resolution << endl;
    }
};


// Derived class Image
class Image : public Media {
private:
    string name;         // Stores image name
    string format;       // Stores image format

public:

    // Constructor
    Image(string n, string f)
        : name(n), format(f) {}

    // Implements play()
    void play() const override {
        cout << "Displaying image: " << name << endl;
    }

    // Implements pause()
    void pause() const override {
        cout << "Image cannot be paused." << endl;
    }

    // Implements stop()
    void stop() const override {
        cout << "Closing image: " << name << endl;
    }

    // Displays image details
    void showDetails() const override {
        cout << "Image: " << name
             << " | Format: " << format << endl;
    }
};


int main() {

    // Collection of base-class pointers
    vector<unique_ptr<Media>> mediaItems;

    // Add Audio object
    mediaItems.push_back(
        make_unique<Audio>("Believer", "Imagine Dragons")
    );

    // Add Video object
    mediaItems.push_back(
        make_unique<Video>("C++ Tutorial", "1080p")
    );

    // Add Image object
    mediaItems.push_back(
        make_unique<Image>("Nature Photo", "JPG")
    );

    cout << "===== MEDIA PLAYER =====" << endl;

    // Traverse through all media objects
    for (const auto& media : mediaItems) {

        // Display details of the current media
        media->showDetails();

        // Play the media
        media->play();

        // Pause the media
        media->pause();

        // Stop the media
        media->stop();

        cout << endl;
    }

    return 0;    // End of program
}
