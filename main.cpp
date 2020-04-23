#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Camera{
    protected:
int capCamera;
vector <bool> ocupat;

public:
    Camera(int capCamera) : capCamera(capCamera){};
    virtual void tip_Camera () = 0;
    virtual void set_ocupat_0 (){
        for (auto i = ocupat.begin() ; i != ocupat.end() ; ++i)
            ocupat.push_back(0);
    }
    virtual bool get_ocupat_i(int i){
        return ocupat[i];
    }
    virtual void set_ocupat(int i){
        ocupat[i] = true;
    }
    virtual void set_liber (int i){
        ocupat[i] = false;
    }
    virtual int get_cap (){
    return this -> capCamera;}
    virtual ~Camera(){
        vector <bool>().swap(ocupat);
    }
};
class CameraMica : public Camera{
    public:
CameraMica(int capCamera = 2) : Camera(capCamera){}

CameraMica(const CameraMica& other) : Camera(other.capCamera){}

friend ostream& operator <<(ostream& out, const CameraMica& c){
    out << c.capCamera;
    return out;
}

friend istream& operator >>(istream& in, CameraMica& c){
    in >> c.capCamera;
    return in;
}

CameraMica& operator =(CameraMica& c){
    this -> capCamera = c.capCamera;
}

void tip_Camera() override{
    cout << "Camera standard\n";
}

};

class Apartament : public Camera{
    public:
Apartament(int capCamera = 4) : Camera(capCamera){}
Apartament(const Apartament& other) : Camera(other.capCamera){}

friend ostream& operator <<(ostream& out, const Apartament& a){
    out << a.capCamera;
    return out;
}

friend istream& operator >>(istream& in, Apartament& a){
    in >> a.capCamera;
    return in;
}

Apartament& operator =(Apartament& a){
    this -> capCamera = a.capCamera;
}

void tip_Camera() override{
    cout << "Apartament\n";
    }
};

class Restaurant : public Camera{
    public:
Restaurant( int capCamera) : Camera(capCamera){}
Restaurant(const Restaurant& other) : Camera(other.capCamera){}

friend ostream& operator <<(ostream& out, const Restaurant& r){
    out << r.capCamera;
    return out;
}

friend istream& operator >>(istream& in, Restaurant& r){
    in >> r.capCamera;
    return in;
}

Restaurant& operator =(Restaurant& r){
    this -> capCamera = r.capCamera;
}

void tip_Camera() override{
    cout << "Restaurant\n";
    }


};

class SalaConferinta : public Camera{
    char tipSalaConf;
public:
    SalaConferinta (int capCamera, char tipSalaConf): Camera(capCamera), tipSalaConf(tipSalaConf){}

    SalaConferinta(const SalaConferinta& other, char tipSalaConf) : Camera(other.capCamera), tipSalaConf(tipSalaConf){}

friend ostream& operator <<(ostream& out, const SalaConferinta& s){
    out << s.capCamera;
    out << ' ';
    out << s.tipSalaConf;
    return out;
}

friend istream& operator >>(istream& in, SalaConferinta& s){
    in >> s.capCamera;
    in >> s.tipSalaConf;
    return in;
}

SalaConferinta& operator =(SalaConferinta& s){
    this -> capCamera = s.capCamera;
    this -> tipSalaConf = s.tipSalaConf;
}

void set_tip_sala(char c){
    this -> tipSalaConf = c;
}

void tip_Camera() override{
    cout << "tipSalaConf";
    }
};


int main()
{int  nrCamere, nrApartamente, nrSaliConf;
CameraMica c[256];
Apartament a[256];
Restaurant r(200);
cout << "Proiectarea hotelului!\n";
cout << "Introduceti numarul total de camere: ";
cin >> nrCamere;
for (int i = 0 ; i < nrCamere ; ++i){
    cin >> c[i];
    c[i].set_ocupat_0();
}
cout << "Introduceti numarul total de apartamente: ";
cin >> nrApartamente;
for (int i = 0 ; i < nrApartamente ; ++i){
    cin >> a[i];
    a[i].set_ocupat_0();}

cout << "Introduceti numarul total de sali de conferinta: ";
cin >> nrSaliConf;

cout << endl;
cout << "Bine ati venit la hotelul X! Selectati optiunea: (1/2) " << endl;
cout << "1. Faceti o rezervare" << endl;
cout << "2. Anulati o rezervare" << endl;

int choice, nrPers, nrCamera, nrApartament, prefRestaurant, curentRestaurant = 0;
char preferinta[20];
cin >> choice;
if (choice == 1){
    cout << "Introduceti numarul de persoane: ";
    cin >>nrPers;
    while(nrPers > 0){
        cout << "Preferinte: camera/apartament?";
        cin >> preferinta;
        if(preferinta == "camera"){
            cout << "Selectati numarul camerei dorite.";
            cin >> nrCamera;
            if (c[nrCamera].get_ocupat_i(nrCamera) == false){
                c[nrCamera].set_ocupat(nrCamera);
                cout << "Varianta dumneavoastra este valabila!";
                nrPers -=2;}
            else
            cout << "Imi pare rau, selectati alta camera.";}
        else
            cout << "Selectati numarul apartamentului dorit.";
            cin >> nrApartament;
            if(a[nrApartament].get_ocupat_i(nrApartament) == false){
                cout << "Varianta dumneavoastra este valabila!";
                a[nrApartament].set_ocupat(nrApartament);
                nrPers-=4;
            }

        cout << "Doriti sa ocupati restaurant? (1 pt da, 2 pt nu)";
        cin >> prefRestaurant;
        if (prefRestaurant == 1 && curentRestaurant <= r.get_cap()){
            curentRestaurant += nrPers;

        }
        else cout << "Ne pare rau, nu mai avem locuri libere in restaurant.";
    }
}

else
{cout << "Ocupati camere, apartamente sau ambele?";
cin >> preferinta;
if (preferinta == "camere"){
    cout << "Introduceti numarul camerei.";
    cin >> nrCamera;
    c[nrCamera].set_liber(nrCamera);

}
else if (preferinta == "apartamente"){
    cout << "Introduceti numarul apartamentului";
    cin >> nrApartament;
    c[nrApartament].set_liber(nrApartament);}
else{
    cout << "Introduceti numarul camerei.";
    cin >> nrCamera;
    c[nrCamera].set_liber(nrCamera);
    cout << "Introduceti numarul apartamentului";
    cin >> nrApartament;
    c[nrApartament].set_liber(nrApartament);
}
}

}



