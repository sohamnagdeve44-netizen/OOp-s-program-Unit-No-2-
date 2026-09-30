#include <iostream>  // Provides input and output operations.
#include <memory>    // Provides smart pointers.
#include <string>    // Provides the string class.
#include <vector>    // Provides the vector container.

class Media {
    // Defines the abstract base class Media.

protected:

    std::string title;
    // Stores the media title.

public:

    explicit Media(std::string mediaTitle)
        : title(std::move(mediaTitle)) {}
    // Constructor initializes the media title.

    virtual void play() const = 0;
    // Declares play() as a pure virtual function.

    virtual void pause() const = 0;
    // Declares pause() as a pure virtual function.

    virtual void stop() const = 0;
    // Declares stop() as a pure virtual function.

    virtual void showDetails() const = 0;
    // Declares showDetails() as a pure virtual function.

    virtual ~Media() = default;
    // Defines a virtual destructor for safe polymorphic destruction.
};

class Audio : public Media {
    // Defines Audio as a derived class.

private:

    std::string artist;
    // Stores the artist name.

public:

    Audio(std::string mediaTitle, std::string mediaArtist)
        : Media(std::move(mediaTitle)),
          artist(std::move(mediaArtist)) {}
    // Constructor initializes title and artist.

    void play() const override {
        // Overrides the play() function.

        std::cout << "Playing audio: "
                  << title << '\n';
        // Displays the audio playback message.
    }

    void pause() const override {
        // Overrides the pause() function.

        std::cout << "Pausing audio: "
                  << title << '\n';
        // Displays the audio pause message.
    }

    void stop() const override {
        // Overrides the stop() function.

        std::cout << "Stopping audio: "
                  << title << '\n';
        // Displays the audio stop message.
    }

    void showDetails() const override {
        // Overrides the showDetails() function.

        std::cout << "Audio | Title: "
                  << title
                  << " | Artist: "
                  << artist << '\n';
        // Displays audio details.
    }
};

class Video : public Media {
    // Defines Video as a derived class.

private:

    std::string resolution;
    // Stores the video resolution.

public:

    Video(std::string mediaTitle, std::string videoResolution)
        : Media(std::move(mediaTitle)),
          resolution(std::move(videoResolution)) {}
    // Constructor initializes title and resolution.

    void play() const override {
        // Overrides the play() function.

        std::cout << "Playing video: "
                  << title << '\n';
        // Displays the video playback message.
    }

    void pause() const override {
        // Overrides the pause() function.
std::cout << "Pausing video: "
                  << title << '\n';
        // Displays the video pause message.
    }

    void stop() const override {
        // Overrides the stop() function.

        std::cout << "Stopping video: "
                  << title << '\n';
        // Displays the video stop message.
    }

    void showDetails() const override {
        // Overrides the showDetails() function.

        std::cout << "Video | Title: "
                  << title
                  << " | Resolution: "
                  << resolution << '\n';
        // Displays video details.
    }
};

class Image : public Media {
    // Defines Image as a derived class.

private:

    std::string format;
    // Stores the image format.

public:

    Image(std::string mediaTitle, std::string imageFormat)
        : Media(std::move(mediaTitle)),
          format(std::move(imageFormat)) {}
    // Constructor initializes title and format.

    void play() const override {
        // Overrides play() for image display.

        std::cout << "Displaying image: "
                  << title << '\n';
        // Displays the image.
    }

    void pause() const override {
        // Overrides pause() for image display.

        std::cout << "Image display paused: "
                  << title << '\n';
        // Displays the pause message.
    }

    void stop() const override {
        // Overrides stop() for image display.

        std::cout << "Closing image: "
                  << title << '\n';
        // Displays the image closing message.
    }

    void showDetails() const override {
        // Overrides the showDetails() function.

        std::cout << "Image | Title: "
                  << title
                  << " | Format: "
                  << format << '\n';
        // Displays image details.
    }
};

int main() {
    // Program execution starts here.

    std::vector<std::unique_ptr<Media>> mediaItems;
    // Creates a collection of base-class smart pointers.

    mediaItems.push_back(
        std::make_unique<Audio>(
            "Perfect",
            "Ed Sheeran"
        )
    );
    // Adds an Audio object to the collection.

    mediaItems.push_back(
        std::make_unique<Video>(
            "C++ Tutorial",
            "1080p"
        )
    );
    // Adds a Video object to the collection.

    mediaItems.push_back(
        std::make_unique<Image>(
            "Campus Photo",
            "JPEG"
        )
    );
    // Adds an Image object to the collection.

    std::cout << "=== Media Player ===\n\n";
    // Displays the program heading.

    for (const auto& media : mediaItems) {
        // Loops through all media objects.

        media->showDetails();
        // Calls the correct showDetails() function.

        media->play();
        // Calls the correct play() function.

        media->pause();
        // Calls the correct pause() function.

        media->stop();
        // Calls the correct stop() function.

        std::cout << '\n';
        // Prints a blank line.
    }

    return 0;
    // Indicates successful program execution.
}
