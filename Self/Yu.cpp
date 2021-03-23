//
//  parent.cpp
//  self
//
//  Created by Vincent Yu on 2/23/18.
//  Copyright © 2018 Vincent Yu. All rights reserved.
//


class Yu :public Human{
public:
    Yu();
    Yu(int theheight, int theage, int theyearofbirth, std::string thenationality);
    void setyearofbirth(int theyearofbirth);
    void setnationality(std::string thenationality);
    int getyearofbirth();
    std::string getnationality();
    void cookfood();
private:
    int yearofbirth;
    std::string nationality;
};

Yu::Yu(){
    Human();
    yearofbirth = 0;
    nationality = "none";
}

Yu::Yuint theheight, int theage, int theyearofbirth, std::string thenationality){
    Human(theheight, theage);
    yearofbirth = theyearofbirth;
    nationality = thenationality;
}

void Yu::setyearofbirth(int theyearofbirth){
    yearofbirth = theyearofbirth;
}

void Yu::setnationality(std::string thenationality){
    nationality = thenationality;
}

int Yu::getyearofbirth(){
    return yearofbirth;
}

std::string Yu::getnationality(){
    return nationality;
}

void Yu::cookfood(){
    cout<< "I will cook food!" <<endl;
}
