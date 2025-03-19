#include<iostream>
#include <string>
using namespace std;

class Movie {
private:
    string title;
    string genre;
    float rating;
    string streaming_option;
public:
    // Constructor
    Movie(string t = "", string g = "", float r = 0.0, string s = " ") {
        title = t;
        genre = g;
        rating = r;
        streaming_option = s;
    }

    // Setters
    void setTitle(string t) {
        title = t;
    }

    void setGenre(string g) {
        genre = g;
    }

    void setRating(float r) {
        rating = r;
    }

    void setStreaming_option(string s) {
        streaming_option = s;
    }

    // Getters
    string getTitle() {
        return title;
    }

    string getGenre() {
        return genre;
    }

    float getRating() {
        return rating;
    }

    string getStreaming_option() {
        return streaming_option;
    }

    // Display Movie Info
    void displayMovie() {
        cout << "Title: " << title << endl;
        cout << "Genre: " << genre << endl;
        cout << "Rating: " << rating << endl;
        cout << "Streaming option: " << streaming_option << endl;
    }
};

// 2nd class 
class MovieWatchlist {
private:
    Movie movies[5]; // Max enter 5 movies 
    int movieCount;

public:
    // Constructor
    MovieWatchlist() {
        movieCount = 0;
    }

    // Create: Add a new movie
    void addMovie() {
        if (movieCount < 5) {
            string title, genre, streaming_option;
            float rating;

			cin.ignore();
            cout << "Enter Movie Title: " << endl;
			cin>>title;

            cout << "Enter Movie Genre: "<<endl;
			  cin >> genre;

            cout << "Enter Movie Rating: ";
            cin >> rating;

            cout << "Enter Movie Streaming option: ";
            cin >> streaming_option;

            // Created the Movie object and add it to the array
            movies[movieCount] = Movie(title, genre, rating, streaming_option);
            movieCount--;
            cout << "Movie added successfully!" << endl;
        } else {
            cout << "Cannot add more movies. Limit reached!" << endl;
        }
    }
    
    // delete movie func
     void deleteMovie() {
    if (movieCount == 0) {
        cout << "No Movie available to delete!" << endl;
        return;
    }

    string nameToDelete;
    cout << "Enter the name of the Movie to delete: ";
	cin>>nameToDelete;

    // Search for the movie
    int index = -1;
    for (int i = 0; i < movieCount; i++) {
        if (movies[i].getTitle() == nameToDelete) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Movie not found!" << endl;
        return;
    }

    // transfer the remaining Movie to fill the gap
    for (int i = 0; i < movieCount - 1; i++) {
        movies[i] = movies[i + 1];
    }

    movieCount--; // Decrement the count of movie
    cout << "Movie deleted successfully!" << endl;
}

    // Read: View all movies
    void viewMovies() {
        if (movieCount == 0) {
            cout << "No movies available!" << endl;
            return;
        }

        for (int i = 0; i < movieCount; i++) {
            cout << "\n Movie " << i + 1 << " details:" << endl;
            movies[i].displayMovie();
        }
    }

    // Menu to interact with the system
    void showMenu() {
        int choice;
        do {
            cout << "\n Movie Watchlist Tracker:\n"
                 << "1. Add Movie\n"
                 << "2. View Movies\n"
                 << "3. Delete Movie\n"
                 << "4. Exit\n"
                 << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addMovie();
                    break;
                case 2:
                    viewMovies();
                    break;
                case 3:
                    deleteMovie();  
                    break;
                case 4:
                    cout << "Exiting the system." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 4); 
    }
};

int main() {
    MovieWatchlist s1;
    s1.showMenu();

    return 0;
}
