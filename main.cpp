#include<vector>
#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<cstring>


using namespace std;

int menu();

int main(int argc,char* argv[]){
	while(true){
		int opcion=menu();
		if(opcion==1){
			cin.ignore();
			cout<<"Ingrese su frase que desea encriptar, no se aceptan Caracteres especiales, numeros ni letras en mayuscula"<<endl;
			string input;
			getline(cin,input);
			char* encrypt=new char[input.length()+1];
			strcpy(encrypt,input.c_str());
			for(int i=0;i<input.length();i++){
				int code=encrypt[i];
				if(code!=32){
					if(code>=120){
						code-=23;
					}else{
						code+=3;
					}
				}
				encrypt[i]=code;
				
			}	
			cout<<"La frase encriptada es: "<<encrypt<<endl;
			delete[] encrypt;
		}else if(opcion==2){
			cin.ignore();
                        cout<<"Ingrese su frase que desea desencriptar, no se aceptan Caracteres especiales, numeros ni letras en mayuscula"<<endl;
                        string input;
                        getline(cin,input);
                        char* dencrypt=new char[input.length()+1];
                        strcpy(dencrypt,input.c_str());
                        for(int i=0;i<input.length();i++){
                                int code=dencrypt[i];
                                if(code!=32){
                                        if(code<=99){
                                                code+=23;
                                        }else{
                                                code-=3;
                                        }
                                }
                                dencrypt[i]=code;
                        }
                        cout<<"La frase encriptada es: "<<dencrypt<<endl;
			delete[] dencrypt;
		}else if(opcion==3){
			bool valido=false;
			long int tarjeta;
			while(!valido){
				cout<<"Ingrese el numero de su tarjeta de credito (16 cifras) que desea verificar (solamente numeros. Ej: 1234123412341234 "<<endl;
				cin>>tarjeta;	
				if(tarjeta>999999999999999&&tarjeta<10000000000000000){
					valido=true;
				}
			}
			string castear=to_string(tarjeta);
			char* card=new char[17];
			card=strcpy(card,castear.c_str());
			vector<int> caesar;
			int suma=0;
			for(int i=0;i<16;i++){
				caesar.push_back(card[i]-'0');
				if(i%2==0){
					caesar[i]*=2;
					if(caesar[i]>=10){
						int temp=caesar[i]-9;
						caesar[i]=temp;
					}
				}
				suma+=caesar[i];
			}
			string a=to_string(suma);
			if(suma>=10){
				if(a.at(1)=='0'){
					cout<<"LA TARJETA ES VALIDA! VAYA GASTE TODO SU DINERO SIN PREOCUPACION!"<<endl;
				}else{
					cout<<"LA TARJETA ES FALSA, LA POLICIA HA SIDO LLAMADA Y SU UBICACION HA SIDO RASTREADA"<<endl;
				}
			}else{
				cout<<"LA TARJETA ES FALSA, LA POLICIA HA SIDO LLAMADA Y SU UBICACION HA SIDO RASTREADA"<<endl;
			}
			delete[] card;
				
		}
	}	
}


int menu(){
	int rValue;
	while(true){
		cout<<"1.- Encriptar frase\n2.- Desencriptar frase\n3.- Verificar tarjeta\n4.- Salir\n"<<endl;
		cin>>rValue;
		if(rValue==1||rValue==2||rValue==3){
			return rValue;
		}else if(rValue==4){
			cout<<"\n\nGracias por usar este programa!"<<endl;
			exit(0);
		}else{
			cerr<<"Opcion no valida, ingrese su opcion de nuevo"<<endl;
		}
	}
}
