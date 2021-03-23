//
//  main.cpp
//  self
//
//  Created by Vincent Yu on 2/23/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//


class Vincent: public Yu{
public:
    Vincent();
    Vincent(int theheight, int theage, int theyearofbirth, std::string thenationality, int thelinesofcodewritten, std::string themood);
    void linesofcodewritten();
    void setmood(std::string themood);
    int getlinesofcodewritten();
    std::string getmood();
    void cookfood();
private:
    int linesofcodewritten;
    std::string mood;
};

Vincent::Vincent(){
    Parent();
    linesofcodewritten = 0;
    mood = "none";
}

Vincent::Vincent(int theheight, int theage, int theyearofbirth, std::string thenationality, int thelinesofcodewritten, std::string themood){
    Parent(theheight, theage, theyearofbirth, thenationality);
    linesofcodewritten = thelinesofcodewritten;
    mood = themood;
}

void Vincent::linesofcodewritten(){
    linesofcodewritten = linesofcodewritten +1;
}

void Vincent::setmood(std::string themood){
    mood = themood;
}

int Vincent::getlinesofcodewritten(){
    return linesofcodewritten;
}

std::string Vincent::getmood(){
    return mood;
}

void Vincent::cookfood(){
    if (mood == "happy") {
        cout<<"I will cook food" <<endl;
    }
    else{
        cout<< "No!" <<endl;
    }
}

