/**
 * Delaney Fisher
 * CS 124
 * Section A
 */

#ifndef PROJECT_01_SPOTIFY_H
#define PROJECT_01_SPOTIFY_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

/**
 * Class representing data for the top 10,000 songs on Spotify.
 * Data sourced from https://www.kaggle.com/datasets/rakkesharv/spotify-top-10000-streamed-songs
 *
 * Fields
 *      position: a unique integer; represents the song’s position on the charts
 *      artist: a string; the name of the artist of each song
 *      title: a string; the title of each song
 *      days: an integer; the number of days since the release of the song (at the time the dataset was created)
 *      streams: an integer; the total number of times the song has been streamed (at the time the dataset was created)
 */

class Spotify {

private:
    // Fields
    string artist, title;
    int position, days, streams;

public:
    // Constructors
    //Default
    Spotify();

    // Non-default
    Spotify(int position, string artist, string title, int days, int streams);

    // Getters
    int getPosition() const;
    string getArtist() const;
    string getTitle() const;
    int getDays() const;
    int getStreams() const;

    // Setters
    void setPosition(int position);
    void setArtist(string artist);
    void setTitle(string title);
    void setDays(int days);
    void setStreams(int streams);

    /**
     * Overload stream insertion operator for pretty printing
     */
    friend ostream &operator<<(ostream &outs, const Spotify &sObj);

    // Overloaded comparison operators
    friend bool operator < (const Spotify& lhs, const Spotify& rhs);
    friend bool operator > (const Spotify& lhs, const Spotify& rhs);
    friend bool operator <= (const Spotify& lhs, const Spotify& rhs);
    friend bool operator >= (const Spotify& lhs, const Spotify& rhs);
    friend bool operator == (const Spotify& lhs, const Spotify& rhs);
    friend bool operator != (const Spotify& lhs, const Spotify& rhs);

    // Other functions
    /**
    * Read data into a vector from the downloaded CSV file.
    * Returns true if all data is loaded correctly, false otherwise.
    * @param fn
    * @param songs vector
    */
    bool loadFromFile(string fn, vector<Spotify>& songs);

    /**
     * Given a vector of song object, group songs by number of streams
     * @param songs vector
     */
    void showStreamingStats(vector<Spotify>& songs);

    /**
     * Ensures that all fields have valid values by comparing the values to sentinels
     * that were set earlier
     *
     * @param songs vector
     */
    void verifyAllFieldsSet(vector<Spotify>& songs);

    /**
     * Uses assertions to ensure that constructors, getters, and setters are
     * functioning properly
     */
    void spotifyTest();

};

#endif //PROJECT_01_SPOTIFY_H