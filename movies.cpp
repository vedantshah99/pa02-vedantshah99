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