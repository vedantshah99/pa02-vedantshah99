#include <vector>
#include <string>
using namespace std;

#indef MOVIES_H
#define MOVIES_H

class Movie{
    public:
        string getTitle(){return title;}
        double getRating() {return rating;}

        Movie(string title, double rating);
        Movie();
        bool operator>(const Movie& m);
        bool operator<(const Movie& m);
        bool operator==(const Movie& m);

    private:
        string title;
        double rating
}


#endif