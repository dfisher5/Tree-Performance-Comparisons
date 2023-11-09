#include "Spotify.h"

/************* Spotify class ******************/

Spotify::Spotify() {}

Spotify::Spotify(int position, string artist, string title, int days, int streams) {
    this->position = position;
    this->artist = artist;
    this->title = title;
    this->days = days;
    this->streams = streams;
}

// Getters
int Spotify::getPosition() const {
    return position;
}
string Spotify::getArtist() const {
    return artist;
}
string Spotify::getTitle() const {
    return title;
}
int Spotify::getDays() const {
    return days;
}
int Spotify::getStreams() const {
    return streams;
}

// Setters
void Spotify::setPosition(int position) {
    this->position = position;
}
void Spotify::setArtist(string artist) {
    this->artist = artist;
}
void Spotify::setTitle(string title) {
    this->title = title;
}
void Spotify::setDays(int days) {
    this->days = days;
}
void Spotify::setStreams(int streams) {
    this->streams = streams;
}

// Overloading stream insertion
ostream &operator<<(ostream &outs, const Spotify &sObj) {
    outs << fixed
         << left
         << "   "
         << setw(8) << sObj.getPosition()
         << setw(15) << sObj.getArtist()
         << setw(46) << sObj.getTitle()
         << setw(11) << sObj.getDays()
         << setw(8) << sObj.getStreams();
    return outs;
}

// Overloading comparison operators
bool operator < (const Spotify& lhs, const Spotify& rhs) {
    return lhs.getPosition() < rhs.getPosition();
}

bool operator > (const Spotify& lhs, const Spotify& rhs) {
    return lhs.getPosition() > rhs.getPosition();
}

bool operator <= (const Spotify& lhs, const Spotify& rhs) {
    return lhs.getPosition() <= rhs.getPosition();
}

bool operator >= (const Spotify& lhs, const Spotify& rhs) {
    return lhs.getPosition() >= rhs.getPosition();
}

bool operator == (const Spotify& lhs, const Spotify& rhs) {
    return lhs.getPosition() == rhs.getPosition();
}

bool operator != (const Spotify& lhs, const Spotify& rhs) {
    return lhs.getPosition() != rhs.getPosition();
}

// Other functions
bool Spotify::loadFromFile(string fn, vector<Spotify>& songs) {
    ifstream fin;
    fin.open(fn);

    if (!fin) {
        // File could not be opened
        return false;
    }

    // Get rid of header
    string header = "";
    getline(fin, header);

    // Read in data while the file is still good
    // and we haven't reached the EOF
    int counter = 1;
    while (fin && fin.peek() != EOF) {
        // Initialize fields to sentinel values
        int position = -1;
        string artist = "INVALID";
        string title = "INVALID";
        int days = -1;
        int streams = -1;
        char comma = ',';

        // Read values for each song
        fin >> position;
        if (position != counter) {
            cout << position << " != " << counter << endl;
            return false;
        }
        fin >> comma;
        getline(fin, artist, comma);
        getline(fin, title, comma);
        fin >> days;
        fin >> comma;
        fin >> streams;

        // Add values to custom type vector
        Spotify song(position, artist, title, days, streams);
        songs.push_back(song);
        counter += 1;
    }
    fin.close();
    return true;
}

void Spotify::showStreamingStats(vector<Spotify>& songs) {
    int fiveHundredMillion = 0;
    int hundredMillion = 0;
    int tenMillion = 0;
    int million = 0;
    int other = 0;
    int total;

    for(Spotify& spot : songs) {
        int streaming = spot.getStreams();
        if (streaming < 10000000) {
            million += 1;
        } else if (streaming >= 10000000 && streaming < 100000000) {
            tenMillion += 1;
        } else if (streaming >= 100000000 && streaming <= 500000000) {
            hundredMillion += 1;
        } else if (streaming > 500000000) {
            fiveHundredMillion += 1;
        } else {
            other += 1;
        }
    }

    total = million + tenMillion + hundredMillion + fiveHundredMillion + other;

    cout << endl;
    cout << "Streaming statistics" << endl;
    cout << "------------------------------------" << endl;
    cout << "Over 500 million streams" << right << setw(10)
         << fiveHundredMillion << endl;
    cout << "100 - 500 million streams" << right << setw(10)
         << hundredMillion << endl;
    cout << "10 - 100 million streams" << right << setw(12)
         << tenMillion << endl;
    cout << "Less than 10 million streams" << right << setw(8)
         << million << endl;
    cout << "Other" << right << setw(28) << other << endl;
    cout << "------------------------------------" << endl;
    cout << "Total" << right << setw(31)
         << total << endl;
    cout << "====================================" << endl;
}

void Spotify::verifyAllFieldsSet(vector<Spotify>& songs) {
    int i = 0;
    for (Spotify& spot : songs) {
        if (spot.getPosition() != i+1) {
            cout << "Bad value for position at record "
                 << i << endl;
        }
        string artist = spot.getArtist();
        if (artist.compare("INVALID") == 0) {
            cout << "Bad value for artist at record "
                 << i << endl;
        }
        string title = spot.getTitle();
        if (title.compare("INVALID") == 0) {
            cout << "Bad value for title at record "
                 << i << endl;
        }
        if (spot.getDays() == -1) {
            cout << "Bad value for days at record "
                 << i << endl;
        }
        if (spot.getStreams() == -1) {
            cout << "Bad value for streams at record "
                 << i << endl;
        }
        i += 1;
    }
}

void Spotify::spotifyTest() {
    Spotify testObject = Spotify();
    // Test getters and setters
    testObject.setPosition(1);
    assert (testObject.getPosition() == 1);
    testObject.setArtist("Taylor");
    assert (testObject.getArtist() == "Taylor");
    testObject.setTitle("Best song");
    assert (testObject.getTitle() == "Best song");
    testObject.setDays(365);
    assert (testObject.getDays() == 365);
    testObject.setStreams(1000000);
    assert (testObject.getStreams() == 1000000);

    Spotify testObject2 = Spotify(10, "Ariana",
                                  "Good song", 100, 20);
    assert (testObject2.getPosition() == 10);
    assert (testObject2.getArtist() == "Ariana");
    assert (testObject2.getTitle() == "Good song");
    assert (testObject2.getDays() == 100);
    assert (testObject2.getStreams() == 20);
}