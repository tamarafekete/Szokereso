#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "KMP_string.h"
#include "Szokereso.h"
#include <iostream>
#include <ctime>
#include <iostream>

using namespace std;

sf::Font font;
sf::RenderWindow window(sf::VideoMode(1200, 800), "Word Search", sf::Style::Default);

void init_cim(sf::Text& cim) {
    cim.setFont(font);
    cim.setString("WORD SEARCH");
    cim.setCharacterSize(40);
    cim.setFillColor(sf::Color::Black);
    cim.setPosition(window.getSize().x / 2 - cim.getLocalBounds().width / 2, 15);
}

void init_betuk(sf::RectangleShape& negyzet, sf::Text& betu) {
    negyzet.setFillColor(sf::Color::White);
    negyzet.setOutlineThickness(2.f);
    negyzet.setOutlineColor(sf::Color(200, 200,200));
    betu.setFont(font);
    betu.setCharacterSize(25);
    betu.setFillColor(sf::Color::Black);
}

void init_szo(sf::Text& utasitas, sf::Text& keres, sf::Text& talalt, sf::Text& osszes, sf::Text& per) {
    utasitas.setFont(font);
    utasitas.setCharacterSize(35);
    utasitas.setPosition(800, 80);
    utasitas.setFillColor(sf::Color::Black);
    utasitas.setString("The word: ");
    keres.setFont(font);
    keres.setCharacterSize(35);
    keres.setFillColor(sf::Color(50, 20, 20));
    keres.setPosition(810, 140);
    talalt.setFont(font);
    talalt.setCharacterSize(35);
    talalt.setPosition(950, 140);
    talalt.setFillColor(sf::Color(90, 20, 20));
    talalt.setString("0");
    osszes.setFont(font);
    osszes.setCharacterSize(35);
    osszes.setFillColor(sf::Color(50, 20, 20));
    osszes.setPosition(1010, 140);
    per.setFont(font);
    per.setCharacterSize(35);
    per.setFillColor(sf::Color(50, 20, 20));
    per.setPosition(980, 140);
    per.setString(" / ");
}

void init_jatekosok(sf::Text& jatekos1, sf::Text& jatekos2, sf::Text& jatekos1p, sf::Text& jatekos2p) {
    jatekos1.setFont(font);
    jatekos1.setCharacterSize(35);
    jatekos1.setPosition(800, 300);
    jatekos1.setFillColor(sf::Color::Red);
    jatekos1.setString("Player 1: ");
    jatekos2.setFont(font);
    jatekos2.setCharacterSize(35);
    jatekos2.setPosition(800, 350);
    jatekos2.setFillColor(sf::Color::Black);
    jatekos2.setString("Player 2: ");
    jatekos1p.setFont(font);
    jatekos1p.setCharacterSize(35);
    jatekos1p.setPosition(950, 300);
    jatekos1p.setFillColor(sf::Color::Red);
    jatekos1p.setString("0 ");
    jatekos2p.setFont(font);
    jatekos2p.setCharacterSize(35);
    jatekos2p.setPosition(950, 350);
    jatekos2p.setFillColor(sf::Color::Black);
    jatekos2p.setString("0 ");
}

void init_ora(sf::Clock& clock, sf::Text& time, sf::Text& mp) {
    time.setFont(font);
    time.setCharacterSize(35);
    time.setPosition(800, 400);
    time.setFillColor(sf::Color(50, 20, 20));
    time.setString("Time left: ");
    mp.setFont(font);
    mp.setCharacterSize(35);
    mp.setPosition(950, 400);
    mp.setFillColor(sf::Color(50, 20, 20));
    mp.setString("10");
}

void init_feltoltes(sf::RectangleShape& R, sf::RectangleShape& R2, sf::Text& textbox1, sf::Text& textbox2, sf::Text& t1, sf::Text& t2, sf::RectangleShape& S, sf::Text& start, sf::Text& hiba) {
    R.setFillColor(sf::Color::White);
    R.setOutlineThickness(2.f);
    R.setOutlineColor(sf::Color(200, 200, 200));
    R.setPosition(window.getSize().x / 2 - 100, 100);
    R2 = R;
    R2.setPosition(window.getSize().x / 2 - 100, 200);
    t1.setFont(font);
    t1.setFillColor(sf::Color::Black);
    t1.setCharacterSize(30);
    t1.setString("Text: ");
    t1.setPosition(400, 100);
    t2.setFont(font);
    t2.setFillColor(sf::Color::Black);
    t2.setCharacterSize(30);
    t2.setString("Words: ");
    t2.setPosition(400, 200);
    textbox1.setFont(font);
    textbox1.setCharacterSize(30);
    textbox1.setPosition(window.getSize().x / 2 - 90, 100);
    textbox1.setFillColor(sf::Color::Black);
    textbox2 = textbox1;
    textbox2.setPosition(window.getSize().x / 2 - 90, 200);
    S.setFillColor(sf::Color(2, 100, 64));
    S.setOutlineThickness(2.f);
    S.setOutlineColor(sf::Color(1, 50, 32));
    S.setPosition(window.getSize().x / 2 - 100, 300);
    start.setFont(font);
    start.setCharacterSize(35);
    start.setString("Start");
    start.setPosition(window.getSize().x / 2 - start.getLocalBounds().width / 2, 300);
    start.setFillColor(sf::Color(15, 230, 140));
    hiba.setFont(font);
    hiba.setCharacterSize(30);
    hiba.setString("Nonexistent file");
    hiba.setPosition(window.getSize().x / 2 - hiba.getLocalBounds().width / 2, 400);
    hiba.setFillColor(sf::Color::Red);
}

void init_vege(sf::Text& j1nyer, sf::Text& j2nyer, sf::Text& dontetlen) {
    j1nyer.setFont(font);
    j1nyer.setCharacterSize(35);
    j2nyer = j1nyer;
    dontetlen = j1nyer;
    j1nyer.setString("Player 1 wins!");
    j2nyer.setString("Player 2 wins!");
    dontetlen.setString("Draw!");
    j1nyer.setPosition(window.getSize().x / 2 - j1nyer.getLocalBounds().width / 2, 100);
    j2nyer.setPosition(window.getSize().x / 2 - j2nyer.getLocalBounds().width / 2, 100);
    dontetlen.setPosition(window.getSize().x / 2 - dontetlen.getLocalBounds().width / 2, 100);
    j1nyer.setFillColor(sf::Color::Red);
    j2nyer.setFillColor(sf::Color::Blue);
    dontetlen.setFillColor(sf::Color::Green);
}

int main()
{
    srand(time(NULL));
    
    font.loadFromFile("times new roman.ttf");
    //cim
    sf::Text cim;
    init_cim(cim);

    //a betuk
    sf::RectangleShape negyzet(sf::Vector2f(30.f, 30.f));
    sf::Text betu;
    init_betuk(negyzet, betu);
    
    char* b = new char[2] {0};
    //a keresendo szo
    sf::Text utasitas;
    sf::Text keres, talalt, per, osszes;
    init_szo(utasitas, keres, talalt, osszes, per);
    int sz_nr;
    int y, x;
    float posX1[289], posY1[289];

    //jatekosok
    sf::Text jatekos1;
    sf::Text jatekos2;
    sf::Text jatekos1p;
    sf::Text jatekos2p;
    init_jatekosok(jatekos1, jatekos2, jatekos1p, jatekos2p);
    int jatekos = 1;
    int pont1 = 1, pont2 = 0;
    bool eger = false;

    //ora
    sf::Clock clock;
    sf::Text time;
    sf::Text mp;
    init_ora(clock, time, mp);
    
    //filetoltes
    sf::RectangleShape R(sf::Vector2f(200.f, 50.f));
    sf::RectangleShape R2(sf::Vector2f(200.f, 50.f));
    sf::Text textbox1, textbox2, t1, t2;
    KMP_string szovegfile, szavakfile;
    bool gameActive = false;
    bool textbox1Active = false;
    bool textbox2Active = false;
    int keypressed = false;
    sf::RectangleShape S(sf::Vector2f(200.f, 50.f));
    sf::Text start;
    sf::Text hiba;
    init_feltoltes(R, R2, textbox1, textbox2, t1, t2, S, start, hiba);

    //Vege
    sf::Text j1nyer, j2nyer, dontetlen;
    init_vege(j1nyer, j2nyer, dontetlen);
    bool volt[100]{ false };
    int talaltdb = 0;
    int szdb = 0;
    bool sztalalt[100]{ false };
    Szokereso word;
    while (window.isOpen())
    {
        sf::Event event;
        if (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(cim);
        
        if (gameActive) { //Ha el van indulva a jatek
            if (talaltdb < word.nrOfWords()) { //Ha meg nincs minden szo kitalalva
                //A betus negyzetek kiirasa
                int m = word.RowLength(), n = word.nrOfRows();
                float posX = 20, posY = 80;
                for (int i = 0;i < n;i++) {
                    for (int j = 0;j < m;j++) {
                        negyzet.setPosition(posX, posY);
                        window.draw(negyzet);
                        b[0] = word.sor.s[i * m + j + i];
                        betu.setString(b);
                        betu.setPosition(posX + (30 - betu.getLocalBounds().width) / 2, posY - 2.5);
                        window.draw(betu);
                        posX += 40;
                    }
                    posY += 40;
                    posX = 20;
                }
                window.draw(utasitas);
                window.draw(keres);
                window.draw(talalt);
                window.draw(per);
                window.draw(osszes);

                if (event.type == sf::Event::MouseButtonPressed) {
                    if (!eger) {
                        eger = true;
                        bool jo = false;
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            for (int i = 0;i < word.tdb[sz_nr];i++) {
                                if (event.mouseButton.x >= posX1[i] && event.mouseButton.x <= posX1[i] + 30 && event.mouseButton.y >= posY1[i] && event.mouseButton.y <= posY1[i] + 30) {
                                    jo = true;
                                    if (!sztalalt[i]) {
                                        szdb++;
                                        sztalalt[i] = true;
                                        KMP_string tl(szdb);
                                        talalt.setString(tl.s);
                                        if (szdb == word.tdb[sz_nr]) {
                                            talaltdb++;
                                            clock.restart();
                                            sz_nr = rand() % word.nrOfWords();
                                            //uj keresendo szo generalasa
                                            if (talaltdb < word.nrOfWords()) {
                                                while (volt[sz_nr]) {
                                                    sz_nr++;
                                                    if (sz_nr == word.nrOfWords()) {
                                                        sz_nr = 0;
                                                    }
                                                }
                                                volt[sz_nr] = true;
                                                keres.setString(word.szavak[sz_nr].s);
                                                for (int i = 0;i < word.tdb[sz_nr];i++) {
                                                    y = word.kezd[sz_nr][i] / (word.RowLength() + 1); x = word.kezd[sz_nr][i] % (word.RowLength() + 1);
                                                    posX1[i] = 20 + x * 40; posY1[i] = 80 + y * 40;
                                                }
                                            }
                                            KMP_string o(word.tdb[sz_nr]);
                                            osszes.setString(o.s);
                                            talalt.setString("0");
                                            szdb = 0;
                                            for (int j = 0;j < word.tdb[sz_nr];j++) sztalalt[j] = false;
                                        }
                                        if (jatekos == 1) {
                                            jatekos = 2;
                                            pont1++;
                                            jatekos1.setFillColor(sf::Color::Black);
                                            jatekos2.setFillColor(sf::Color::Blue);
                                            jatekos1p.setFillColor(sf::Color::Black);
                                            jatekos2p.setFillColor(sf::Color::Blue);
                                            jatekos1p.setString(KMP_string(pont1).s);
                                        }
                                        else {
                                            pont2++;
                                            jatekos = 1;
                                            jatekos1.setFillColor(sf::Color::Red);
                                            jatekos2.setFillColor(sf::Color::Black);
                                            jatekos1p.setFillColor(sf::Color::Red);
                                            jatekos2p.setFillColor(sf::Color::Black);
                                            jatekos2p.setString(KMP_string(pont2).s);
                                        }
                                        clock.restart();
                                        
                                    }
                                }
                            }
                            //ha valamelyik jatekos nem jo helyre kattintott
                            if(!jo) {
                                if (jatekos == 1) {
                                    pont1--;
                                    jatekos1p.setString(KMP_string(pont1).s);
                                }
                                else {
                                    pont2--;
                                    jatekos2p.setString(KMP_string(pont2).s);
                                }
                            }
                        }
                    }
                }
                //jatekosok es pontjaik felrajzolasa
                else eger = false;
                window.draw(jatekos1);
                window.draw(jatekos2);
                window.draw(jatekos1p);
                window.draw(jatekos2p);
                window.draw(time);
                sf::Time elapsed = clock.getElapsedTime();
                int t = 10 - elapsed.asSeconds();
               // cout << t << '\n';
                if (t < 1) {
                    if (jatekos == 1) {
                        jatekos = 2;
                        jatekos1.setFillColor(sf::Color::Black);
                        jatekos2.setFillColor(sf::Color::Blue);
                        jatekos1p.setFillColor(sf::Color::Black);
                        jatekos2p.setFillColor(sf::Color::Blue);
                        jatekos1p.setString(KMP_string(pont1).s);
                    }
                    else {
                        jatekos = 1;
                        jatekos1.setFillColor(sf::Color::Red);
                        jatekos2.setFillColor(sf::Color::Black);
                        jatekos1p.setFillColor(sf::Color::Red);
                        jatekos2p.setFillColor(sf::Color::Black);
                        jatekos2p.setString(KMP_string(pont2).s);
                    }
                    t = 10;
                    clock.restart();
                }
                mp.setString(KMP_string(t).s);
                window.draw(mp);
                window.display();
            }
            else {
                //A jatek vege
                if (pont1 > pont2) {
                    window.draw(j1nyer);
                }
                else if (pont2 > pont1) {
                    window.draw(j2nyer);
                }
                else {
                    window.draw(dontetlen);
                }
                window.display();
            }
        }
        else { //A jatek eleje - a ket file feltoltese
            window.draw(R);
            window.draw(R2);
            bool err = false;
            if (event.type == sf::Event::MouseButtonPressed) {//rakattintas a szovegdobozokra
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (event.mouseButton.x >= 500 && event.mouseButton.x <= 700 && event.mouseButton.y >= 100 && event.mouseButton.y <= 150) {//elso szovegdoboz
                        textbox1Active = true;
                        textbox2Active = false;
                        R.setOutlineColor(sf::Color::Black);
                        R2.setOutlineColor(sf::Color(200, 200, 200));
                    }
                    else if (event.mouseButton.x >= 500 && event.mouseButton.x <= 700 && event.mouseButton.y >= 200 && event.mouseButton.y <= 250) {//masodik szovegdoboz
                        textbox1Active = false;
                        textbox2Active = true;
                        R.setOutlineColor(sf::Color(200, 200, 200));
                        R2.setOutlineColor(sf::Color::Black);
                    }
                    else if (event.mouseButton.x >= 500 && event.mouseButton.x <= 700 && event.mouseButton.y >= 300 && event.mouseButton.y <= 350) {//rakattintas a startgonmbra
                        clock.restart();
                        ifstream szoveg(szovegfile.s);
                        ifstream szavak(szavakfile.s);
                        if (szavak.is_open() && szoveg.is_open()) {
                            word.txtbolEpit(szoveg, szavak);
                            for (int i = 0;i < word.nrOfWords();i++) {
                                if (word.tdb[i] == 0) {
                                    volt[i] = true;
                                    talaltdb++;
                                }
                            }
                            sz_nr = rand() % word.nrOfWords();
                            volt[sz_nr] = true;
                            keres.setString(word.szavak[sz_nr].s);
                            for (int i = 0;i < word.tdb[sz_nr];i++) {
                                y = word.kezd[sz_nr][i] / (word.RowLength() + 1); x = word.kezd[sz_nr][i] % (word.RowLength() + 1);
                                posX1[i] = 20 + x * 40; posY1[i] = 80 + y * 40;
                            }
                            gameActive = true;
                            szdb = 0;
                            KMP_string o(word.tdb[sz_nr]);
                            osszes.setString(o.s);
                        }
                        else {
                            err = true;
                        }
                    }
                    else {
                        textbox1Active = false;
                        textbox2Active = false;
                        R.setOutlineColor(sf::Color(200, 200, 200));
                        R2.setOutlineColor(sf::Color(200, 200, 200));
                    }
                }
            }
            if (textbox1Active) { //az elso file beirasa
                if (event.type == sf::Event::TextEntered) {
                    if (event.key.code != 8 && !keypressed && szovegfile.size()<12 ){
                        char a[2] = { event.key.code, 0 };
                        szovegfile = szovegfile.append(a);
                        textbox1.setString(szovegfile.s);
                        keypressed = true;
                    }
                    else if (event.key.code == 8 && !keypressed) {
                        szovegfile.deleteLastChar();
                        textbox1.setString(szovegfile.s);
                        keypressed = true;
                    }
                }
                else {
                    keypressed = false;
                }
                
            }
            else if (textbox2Active) {//a masodik file beirasa
                if (event.type == sf::Event::TextEntered) {
                    if (event.key.code != 8 && !keypressed && szavakfile.size()<12) {
                        char a[2] = { event.key.code, 0 };
                        szavakfile = szavakfile.append(a);
                        textbox2.setString(szavakfile.s);
                        keypressed = true;
                    }
                    else if (event.key.code == 8 && !keypressed) {
                        szavakfile.deleteLastChar();
                        textbox2.setString(szavakfile.s);
                        keypressed = true;
                    }
                }
                else {
                    keypressed = false;
                }
            }
            window.draw(textbox1);
            window.draw(textbox2);
            window.draw(S);
            window.draw(start);
            window.draw(t1);
            window.draw(t2);
            if (err == true) {
                window.draw(hiba);
            }
               
            window.display();
        }
    }

    return 0;
}