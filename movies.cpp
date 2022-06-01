//Completed By: Vedant Shah

#include "movies.h"
#include <vector>
#include <string>

using namespace std;

Movie::Movie(){
    title = "";
    rating = 0;
}

Movie::Movie(string mTitle, double mRating){
    title = mTitle;
    rating = mRating;
}

bool Movie::operator<(const Movie& m){
    if(title < m.title){
        return true;
    }
    return false;
}

bool Movie::operator>(const Movie& m){
    if(title > m.title){
        return true;
    }
    return false;
}

bool Movie::operator==(const Movie& m){
    if(title == m.title){
        return true;
    }
    return false;
}

bool compare_rating(Movie m1, Movie m2){
    if(m1.getRating() < m2.getRating()){
        return false;
    }
    if(m1.getRating() > m2.getRating()){
        return true;
    }
    if(m1.getRating() == m2.getRating()){
        return (m1.getTitle() < m2.getTitle());
    }
    return true;
}