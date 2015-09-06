#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <iomanip.h>
#include <math.h>
#define BLACK 0
#define LIGHTGRAY 8
#define BLUE 9
#define GREEN 10
#define RED 12
#define YELLOW 14
#define WHITE 15
#define BACKMENU {cout<<"Nhap nut bat ki quay lai menu."; getch();}
using namespace std;

void textcolor(WORD color)                                                      /* Khai bao mot so ham phuc vu menu dong */
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void textbackground(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void gotoxy(short x,short y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x,y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

void ancontro()
{
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
    SetConsoleCursorInfo(hOut,&ConCurInf);
}
void hiencontro()
{
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = TRUE;
    SetConsoleCursorInfo(hOut,&ConCurInf);
}
struct sach{
        long mss;
        char tensach[50];
        char linhvuc[50];
        float Danhgia;
        long ngay;
        int thang;
        int nam;
        };                                                                      /* khai bao bo nho */
template<class T>                                                                /* dinh nghia ham doi cho hai phan tu */
void doicho(T &a,T &b)
{ T c;
c=a;a=b;b=c;}
void doicho(char a[],char b[]){
     char cn[1000];
     strcpy(cn,a);
     strcpy(a,b);
     strcpy(b,cn);
     };

                             
void hienthi(){                                                                  /* dinh nghia ham hien thi khung danh sach */
                   cout<<setw(5)<<"MSS:";
                   cout<<setw(18)<<"Ten sach: ";
                   cout<<setw(18)<<"Linh Vuc: ";
                   cout<<setw(22)<<"Ngay xuat ban: ";
                   cout<<setw(15)<<"Diem xep hang:";
                   cout<<endl;
                   }
int lc;                                                                          /* bien toan cuc lc */
class danhsach                                                                   /* lop danh sach */
{
       private:
       
       int k,n;
       sach sak[600];                                                         /* khai bao 600 phan tu */
                                                                 
       public: 
                danhsach(){int k=0; int n=0;};                                   /* ham tao */
                int nhapsak() {                                                   /* ham nhap thong tin sach */
                                   textcolor(15);
                                   system("cls");                                
                                   k=n;
                                   int i,dem=0,dem1;
                                   gotoxy(25,3);
                                   cout<<"Thong tin quyen sach thu "<<k+1<<endl;
                         
                                   do{
                                      do{  
                                      cout<<"\nNhap mss: ";
                                      cin>>sak[k].mss;
                                      if ((sak[k].mss<=00000000)||(sak[k].mss>=99999999)) cout<<"Ma so sach khong hop le, moi nhap lai";
                                      } while((sak[k].mss<=00000000)||(sak[k].mss>=99999999));  
                              
                                   for (i=0;i<n;i++)
                                   {   if (sak[k].mss==sak[i].mss) dem++;
                                   }
                                               
                                   if (dem!=0) cout<<"Ma sach da ton tai. Xin moi nhap lai ma so sach khac";
                                   dem1=dem;
                                   dem=0;                                                                   /* Kiem tra ma sach da ton tai hay chua va co hop le khong */
                              
                                    }while(dem1!=0);      
                                                 	 
                            	    cout<<"Nhap ten sach: ";
                               	    cin.ignore();
                               	    cin.getline( sak[k].tensach, 50 );
                               	    cout<<"Linhvuc(vd: Truyen cuoi): ";
                               	    cin.getline( sak[k].linhvuc, 50);
                    	 
                    	            cout<<"Nhap ngay/thang/nam xuat ban:"<<endl;
                    	            do{ 
                                        do{
                                	       do{ 
                                           cout<<"\n\tNgay xuat ban: ";cin>>sak[k].ngay;
                                	       if ((sak[k].ngay<=0)||(sak[k].ngay>31)) cout<<"Ngay xuat ban khong hop le, xin moi nhap lai ";
                                           } while ((sak[k].ngay<=0)||(sak[k].ngay>31));
                                	       do{ cout<<"\n\tThang xuat ban: "; cin>>sak[k].thang;
                                	       if ((sak[k].thang<=0)||(sak[k].thang>12)) cout<<"Thang xuat ban khong hop le, xin moi nhap lai";
                                           } while ((sak[k].thang<=0)||(sak[k].thang>12));
                                	       do { 
                                           cout<<"\n\tNam xuat ban: ";
                           	               cin>>sak[k].nam;
                                	       if ((sak[k].nam<=0)||(sak[k].nam>=2014)) cout<<"Nam xuat ban khong dung, xin moi nhap lai";
                                           }while((sak[k].nam<=0)||(sak[k].nam>=2014));
                                        if ((sak[k].ngay==29)&&(sak[k].thang==2)&&(sak[k].nam%4!=0))  cout<<"Nam nhap khong phai nam nhuan, moi nhap lai ngay thang nam xuat ban";                                       
                     	                }while((sak[k].ngay==29)&&(sak[k].thang==2)&&(sak[k].nam%4!=0));
                        	        if ((sak[k].ngay==30)&&(sak[k].thang==2)) cout<<"Thong tin khong dung, xin moi nhap lai ngay thang nam xuat ban";
                    	            }while ((sak[k].ngay==30)&&(sak[k].thang==2));                                               /* Lenh kiem tra thong tin ngay xuat ban co hop le khong*/
                    	            do{
                                    cout<<"Diem xep hang sach: ";
                    	            cin>>sak[k].Danhgia;
                    	            if(sak[k].Danhgia<0.00||sak[k].Danhgia>10.00) cout<<"Ban co chac chan ve xep hang cua quyen sach nay? Xin moi nhap lai. "<<endl;
                                    }while(sak[k].Danhgia<0.00||sak[k].Danhgia>10.00);                                                   /* kiem tra xep hang nhap vao co chinh xac khong */
                    	 
                    	            n++;            /* Sau moi lan quay lai menu se nhap duoc quyen sach tiep theo */
                    	 
                                    
                                    
                         
                         };
                void inra(){                                                     /* ham in ra danh sach */
                                    textcolor(15);
                                    system("cls");
                                    int i;
                                    gotoxy(0,3);
                                    hienthi();
                                    for (i=0;i<n;i++) {
                     
                                        cout<<setw(5)<<sak[i].mss;
                 
                                        cout<<setw(20)<<sak[i].tensach;
                 
                                        cout<<setw(18)<<sak[i].linhvuc;
                 
                                        cout<<setw(5)<<sak[i].ngay<<"/"<<setw(2)<<sak[i].thang<<"/"<<setw(2)<<sak[i].nam;
                 
                                        cout<<setw(15)<<sak[i].Danhgia<<endl;
                                        };
                 
                            };            
                 void xuatfile(){   
                                    textcolor(15);
                                    system("cls");                               /* xuat ra file */
                                    int j;
                                    ofstream SAK ("SAK.bin");
                                    SAK<<n<<"\n";     
                                    for(j=0;j<n;j++){ 
                                       SAK<<sak[j].mss;
                                       SAK<<endl;
                                       SAK<<sak[j].linhvuc;
                                       SAK<<endl;
                                       SAK<<sak[j].Danhgia;
                                       SAK<<endl;
                                       SAK<<sak[j].tensach;
                                       SAK<<endl;
                                       SAK<<sak[j].ngay;
                                       SAK<<endl;
                                       SAK<<sak[j].thang;
                                       SAK<<endl;
                                       SAK<<sak[j].nam;
                                       SAK<<endl;
                                       }
                                    gotoxy(30,3);
                                    cout<<"Da luu ra file sak.bin"<<endl;
                                    
                                };
                 int mofile(){     
                                   textcolor(15);
                                   system("cls");                                /* Mo file  */
                                   int l;
                                   ifstream SAK ("SAK.bin");
                                    
                                   if(! SAK.is_open())
                                        {
                                            cout<<"File khong ton tai, xin moi quay lai menu de tao file.\n";
                                            BACKMENU;
                                            return 0;
                                        }
                                    
                                   else { 
                                     SAK>>n;
                                     for(l=0;l<n;l++) 
                                     { SAK>>sak[l].mss;
                                     SAK.getline(sak[l].linhvuc,250);
                                     SAK.getline(sak[l].linhvuc,250);
                                     SAK>>sak[l].Danhgia;
                                     SAK.getline(sak[l].tensach,250);
                                     SAK.getline(sak[l].tensach,250);
                                     SAK>>sak[l].ngay;
                                     SAK>>sak[l].thang;
                                     SAK>>sak[l].nam;
                                     }
                                     gotoxy(0,3);
                                     hienthi();      
                                     for(l=0;l<n;l++) { 
                                     cout<<setw(5)<<sak[l].mss;
                 
                                     cout<<setw(20)<<sak[l].tensach;
                 
                                     cout<<setw(18)<<sak[l].linhvuc;
                 
                                     cout<<setw(5)<<sak[l].ngay<<"/"<<setw(2)<<sak[l].thang<<"/"<<setw(2)<<sak[l].nam;
                 
                                     cout<<setw(15)<<sak[l].Danhgia<<endl;}
                                     }
                                     SAK.close();
                                     
                                     
                                     return 1;
                                     
                    };
                    void sapxep(){      
                                     textcolor(15);                            /* ham sap xep Bubble Sort*/
                                     system("cls");                        
                                     int i,j;
                                     long b;
                                     char s[50];
                                     char r[10];
                                     float a;
                                     long c;
                                     int d;
                                     int e;
                                     for(i=0;i<n-1;i++)
                                                       {for(j=n-1;j>i;j--)
                                                       {if (sak[j].Danhgia>sak[j-1].Danhgia){doicho(sak[j-1].mss,sak[j].mss);
                                                            doicho(sak[j-1].Danhgia,sak[j].Danhgia);
                                                            doicho(sak[j-1].ngay,sak[j].ngay);
                                                            doicho(sak[j-1].thang,sak[j].thang);
                                                            doicho(sak[j-1].nam,sak[j].nam);
                                                            doicho(sak[j-1].tensach,sak[j].tensach);
                                                            doicho(sak[j-1].linhvuc,sak[j].linhvuc);};
                                                             }
                                                       };
                                     gotoxy(0,3);
                                     hienthi();
                                     for(i=0;i<n;i++) { 
                                                        cout<<setw(5)<<sak[i].mss;
                                     
                                                        cout<<setw(20)<<sak[i].tensach;
                                     
                                                        cout<<setw(18)<<sak[i].linhvuc;
                                     
                                                        cout<<setw(5)<<sak[i].ngay<<"/"<<setw(2)<<sak[i].thang<<"/"<<setw(2)<<sak[i].nam;
                                     
                                                        cout<<setw(15)<<sak[i].Danhgia<<endl;}
                                    
                   };           
                 
                   void timkiem(){                                               /* ham tim kiem sach*/                                                     
                                     textcolor(15);  
                                     system("cls");  
      
                                     long masak,mss1;
                                     char ht[50];
                                     float diem;
                                     int i,j=0,dem=0,dem1=0,dem2=0,l=0,m,d;
                                     int kt=0,kt1;
                                     int ch;
                                     char chon;
                                     sach sak1[100];
                                     
                                     if (lc==1) { system("cls");
                                     gotoxy(0,3);textcolor(15);
                                        cout<<"Moi ban nhap vao ma sach can tim: ";                   /* tim kiem theo ma sinh vien */                                                          
                                        cin>>masak;
                                        for (i=0;i<n;i++)
                                        { if (sak[i].mss==masak) 
                                                  {  hienthi();
                                                     cout<<setw(5)<<sak[i].mss;
                                     
                                                     cout<<setw(20)<<sak[i].tensach;
                                                     
                                                     cout<<setw(18)<<sak[i].linhvuc;
                                                     
                                                     cout<<setw(5)<<sak[i].ngay<<"/"<<setw(2)<<sak[i].thang<<"/"<<setw(2)<<sak[i].nam;
                                                     
                                                     cout<<setw(15)<<sak[i].Danhgia<<endl;
                                                     
                                                     
                                                     dem++;} 
                                     }
                                     
                                     if (dem==0) cout<<"Khong ton tai quyen sach trong danh sach."<<endl;
                                     else {cout<<"Ban co muon chinh sua thong tin quyen sach nay khong(y/n)? ";
                                         cin>>chon;
                                         if (chon=='y') {                                                        /* goi lai cac buoc de nhap vao thong tin sach moi */                  
                                                           do{
                                                             do{  
                                                             cout<<"\nNhap mss: ";
                                                             cin>>sak[j].mss;
                                                             if ((sak[j].mss<=00000000)||(sak[j].mss>=99999999)) cout<<"Ma sach khong hop le, moi nhap lai";
                                                             
                                                              } while((sak[j].mss<=00000000)||(sak[j].mss>=99999999));  
                                                           for (i=0;i<n;i++)
                                                           {   if (sak[j].mss==sak[i].mss) kt++;
                                                           }
                                                                               
                                                           if (kt>1) cout<<"Ma sach da ton tai. Xin moi nhap lai ma so sach khac"<<endl;
                                                           kt1=kt;
                                                           kt=0;
                                                           }while(kt1>1);      
                                                             
                                                              
                                                              
                                                                               	 
                                                           cout<<"Nhap ten sach: ";
                                                    	   cin.ignore();
                                                    	   cin.getline( sak[j].tensach, 50 );
                                                    	   cout<<"Linhvuc(vd: TRUYEN CUOI): ";
                                                    	   cin.getline( sak[j].linhvuc, 50 );
                                                    	 
                                                    	   cout<<"Nhap ngay/thang/nam xuat ban:"<<endl;
                                                    	   do{ 
                                                                 do{
                                                                	 do{ 
                                                                     cout<<"\n\tNgay xuat ban: ";cin>>sak[j].ngay;
                                                                	 if ((sak[j].ngay<=0)||(sak[j].ngay>31)) cout<<"Ngay xuat ban khong hop le, xin moi nhap lai ";
                                                                     } while ((sak[j].ngay<=0)||(sak[j].ngay>31));
                                                                	 do{ cout<<"\n\tThang xuat ban: "; cin>>sak[j].thang;
                                                                	 if ((sak[j].thang<=0)||(sak[j].thang>12)) cout<<"Thang xuat ban khong hop le, xin moi nhap lai";
                                                                     } while ((sak[j].thang<=0)||(sak[j].thang>12));
                                                                	 do { cout<<"\n\tNam xuat ban: ";
                                                                	 cin>>sak[j].nam;
                                                                	 if ((sak[j].nam<=0)||(sak[j].nam>=2014)) cout<<"Nam xuat ban khong dung, xin moi nhap lai";
                                                                     }while((sak[j].nam<=0)||(sak[j].nam>=2014));
                                                                 if ((sak[j].ngay==29)&&(sak[j].thang==2)&&(sak[j].nam%4!=0))  cout<<"Nam nhap khong phai nam nhuan, moi nhap lai ngay thang nam xuat ban";                                       
                                                            	 
                                                                }while((sak[j].ngay==29)&&(sak[j].thang==2)&&(sak[j].nam%4!=0));
                                                      	        if ((sak[j].ngay==30)&&(sak[j].thang==2)) cout<<"Thong tin khong dung, xin moi nhap lai ngay thang nam xuat ban";
                                               	            }while ((sak[j].ngay==30)&&(sak[j].thang==2));                 
                                                    	    do{
                                                            cout<<"Danh gia sach: ";
                                                   	        cin>>sak[j].Danhgia;
                                                    	    if(sak[j].Danhgia<0.00||sak[j].Danhgia>10.00) cout<<"Ban co chac chan ve diem cua quyen sach nay? Xin moi nhap lai. "<<endl;
                                                            }while(sak[j].Danhgia<0.00||sak[j].Danhgia>10.00);
                                                      }    
                                                      }
                                                               
                                                      };
                                     if (lc==2) { system("cls");                                     
                                     gotoxy(0,3);textcolor(15);
                                             cout<<"Moi ban nhap vao ten sach can tim: ";                        /* tim kiem theo ten sach */ 
                                             
                                             cin.getline(ht,50);
                                             hienthi();
                                             for (i=0;i<n;i++)
                                             
                                             {   
                                                 if (strcmp(sak[i].tensach,ht)==0)
                                                  {  
                                                     cout<<setw(5)<<sak[i].mss;
                                     
                                                     cout<<setw(20)<<sak[i].tensach;
                                                     
                                                     cout<<setw(18)<<sak[i].linhvuc;
                                                     
                                                     cout<<setw(5)<<sak[i].ngay<<"/"<<setw(2)<<sak[i].thang<<"/"<<setw(2)<<sak[i].nam;
                                                     
                                                     cout<<setw(15)<<sak[i].Danhgia<<endl;
                                                     
                                                     dem1++;} 
                                              };
                                              if (dem1==0) cout<<"Khong ton tai quyen sach trong danh sach."<<endl;
                         
                                              };
                       
                                    if(lc==3) { system("cls");
                                    gotoxy(0,3); textcolor(15);
                                             cout<<"Moi ban nhap vao xep hang sach can tim: ";                                    /* tim kiem theo thu hang*/ 
                                             cin>>diem;
                                             hienthi();
                                             for (i=0;i<n;i++)
                                              
                                             { if (sak[i].Danhgia==diem) 
                                                  {  
                                                    
                                                     cout<<setw(5)<<sak[i].mss;
                                     
                                                     cout<<setw(20)<<sak[i].tensach;
                                                     
                                                     cout<<setw(18)<<sak[i].linhvuc;
                                                     
                                                     cout<<setw(5)<<sak[i].ngay<<"/"<<setw(2)<<sak[i].thang<<"/"<<setw(2)<<sak[i].nam;
                                                     
                                                     cout<<setw(15)<<sak[i].Danhgia<<endl;
                                                     
                                                    
                                                     
                                                     dem2++;}
                                                     }
                                             if (dem2==0) cout<<"Khong ton tai quyen sach trong danh sach."<<endl;
                                             
                                             };
                                          
                                     }
                                     
                   void chinhsua(){                                                 /* ham chinh sua thong tin sach trong danh sach */ 
                        
                       textcolor(15);
                       system("cls");
                       float mss1;
                       int m,d,kt=0,kt1;
                       int dem=0;
                       textcolor(15);
                                    
                                    int i;
                                    gotoxy(0,3);
                                    hienthi();
                                    for (i=0;i<n;i++) {
                     
                                        cout<<setw(5)<<sak[i].mss;
                 
                                        cout<<setw(20)<<sak[i].tensach;
                 
                                        cout<<setw(18)<<sak[i].linhvuc;
                 
                                        cout<<setw(5)<<sak[i].ngay<<"/"<<setw(2)<<sak[i].thang<<"/"<<setw(2)<<sak[i].nam;
                 
                                        cout<<setw(15)<<sak[i].Danhgia<<endl;
                                        };
                       cout<<"Ban muon chinh sua thong tin sach co ma so: ";
                       cin>>mss1;
                                         
                       for(m=0;m<n;m++) 
                       if (sak[m].mss==mss1) {
                       dem++;      
                       do{                                                                                            /* goi lai cac buoc de nhap vao thong tin sach*/
                          do{  
                          cout<<"\nNhap mss: ";
                          cin>>sak[m].mss;
                          if ((sak[m].mss<=00000000)||(sak[m].mss>=99999999)) cout<<"Ma sach khong hop le, moi nhap lai";
                                                             
                          } while((sak[m].mss<=00000000)||(sak[m].mss>=99999999));  
                          for (d=0;d<n;d++)
                          {   if (sak[m].mss==sak[d].mss) kt++;
                          }                                                    
                          if (kt>1) cout<<"Ma sach da ton tai. Xin moi nhap lai ma so sach khac"<<endl;
                          kt1=kt;
                          kt=0;
                          }while(kt1>1);      
                          cout<<"Nhap ten: ";
                        	 cin.ignore();
                        	 cin.getline( sak[m].tensach, 50 );
                        	 cout<<"Linhvuc(vd: Truyen cuoi): ";
                             cin.getline( sak[m].linhvuc, 50 );
                                                    	 
                           	 cout<<"Nhap ngay/thang/nam xuat ban:"<<endl;
                           	 do{ 
                                 do{
                           	        do{ 
                                    cout<<"\n\tNgay xuat ban: ";cin>>sak[m].ngay;
                               	    if ((sak[m].ngay<=0)||(sak[m].ngay>31)) cout<<"Ngay xuat ban khong hop le, xin moi nhap lai ";
                                    } while ((sak[m].ngay<=0)||(sak[m].ngay>31));
                               	    do{ cout<<"\n\tThang xuat ban: "; cin>>sak[m].thang;
                               	    if ((sak[m].thang<=0)||(sak[m].thang>12)) cout<<"Thang xuat ban khong hop le, xin moi nhap lai";
                                    } while ((sak[m].thang<=0)||(sak[m].thang>12));
                               	    do { cout<<"\n\tNam xuat ban: ";
                               	    cin>>sak[m].nam;
                               	    if ((sak[m].nam<=0)||(sak[m].nam>=2014)) cout<<"Nam xuat ban khong dung, xin moi nhap lai";
                                    }while((sak[m].nam<=0)||(sak[m].nam>=2014));
                                 if ((sak[m].ngay==29)&&(sak[m].thang==2)&&(sak[m].nam%4!=0))  cout<<"Nam nhap khong phai nam nhuan, moi nhap lai ngay thang nam xuat ban ";                                       
                           	     }
                               	 while((sak[m].ngay==29)&&(sak[m].thang==2)&&(sak[m].nam%4!=0));
                               	 if ((sak[m].ngay==30)&&(sak[m].thang==2)) cout<<"Thong tin khong dung, xin moi nhap lai ngay thang nam xuat ban ";
                           	 }while ((sak[m].ngay==30)&&(sak[m].thang==2));                 
                           	 do{
                             cout<<"Xep hang sach: ";
                           	 cin>>sak[m].Danhgia;
                           	 if(sak[m].Danhgia<0.00||sak[m].Danhgia>10.00) cout<<"Ban co chac chan ve xep hang cua sinh vien nay? Xin moi nhap lai. "<<endl;
                             }while(sak[m].Danhgia<0.00||sak[m].Danhgia>10.00);
                             }  
                          if (dem==0) cout<<"Khong ton tai sach can chinh sua";                              
                          };  
                   void xoasak(){                                               /* ham xoa sach theo mss*/
                        
                        textcolor(15);
                        system("cls");
                        long mss;
                        int i,j,m,dem=0;
                        gotoxy(0,3);
                        cout<<"Ban muon xoa sach co mss: ";
                        cin>>mss;
                        
                        for(m=0;m<n;m++) 
                        if (sak[m].mss==mss) { 
                                            for (i=m;i<n-1;i++) {
                                                              sak[i].mss=sak[i+1].mss;
                                                              sak[i].ngay=sak[i+1].ngay;
                                                              sak[i].thang=sak[i+1].thang;
                                                              sak[i].nam=sak[i+1].nam;
                                                              sak[i].Danhgia=sak[i+1].Danhgia;
                                                              strcpy(sak[i].tensach,sak[i+1].tensach);
                                                              strcpy(sak[i].linhvuc,sak[i+1].linhvuc);
                                                              }
                                            n=n-1;
                                            dem++;
                                                              } 
                        if (dem==0) {cout<<"Khong ton tai sach co mss: "<<mss<<endl;
                                    }
                        cout<<"Danh sach sau khi xoa sach: "<<endl<<endl;
                        hienthi();
                        for (j=0;j<n;j++)
                                            {       
                                                     cout<<setw(5)<<sak[j].mss;
                                     
                                                     cout<<setw(20)<<sak[j].tensach;
                                                     
                                                     cout<<setw(18)<<sak[j].linhvuc;
                                                     
                                                     cout<<setw(5)<<sak[j].ngay<<"/"<<setw(2)<<sak[j].thang<<"/"<<setw(2)<<sak[j].nam;
                                                     
                                                     cout<<setw(15)<<sak[j].Danhgia<<endl;
                                              };
                        
                        }
                        
};
class menu:public danhsach{                                                       /* lop menu ke thua lop danh sach */                                                 
                  private: int ct,oldlc;
                  public:  
                                        
                  void ten(int n){                         /* ham bao gom mot so dong chu can dung den */
                             switch(n)
                             {        
                                      
                                        case 98:gotoxy(25,0);cout<<"Quay lai"<<endl;                                                                                         break;
                                        case 99: gotoxy(50,0); cout<<"Thoat"<<endl;                                                                                          break;
                                        case 59: { gotoxy(25,1);cout<<"\n\t\t\t+--------+------------------------+";
                                        gotoxy(25,2);cout<<"\n\t\t\t|  STT   + CHUONG TRINH           |";}                                                                   break;
                                        case 60:gotoxy(25,3);cout<<"\n\t\t\t+--------+------------------------+";                                                            break;
                                        case 1:gotoxy(25,4);cout<<"\n\t\t\t|   1    | Nhap danh sach         |";                                                             break;
                                        case 61:gotoxy(25,5);cout<<"\n\t\t\t+--------+------------------------+";                                                            break;
                                        case 2:gotoxy(25,6);cout<<"\n\t\t\t|   2    | In ra danh sach        |";                                                             break;
                                        case 62:gotoxy(25,7);cout<<"\n\t\t\t+--------+------------------------+";                                                            break;
                                        case 3:gotoxy(25,8);cout<<"\n\t\t\t|   3    | Sap xep theo thu hang  |";                                                             break;
                                        case 63:gotoxy(25,9);cout<<"\n\t\t\t+--------+------------------------+";                                                            break;
                                        case 4:gotoxy(25,10);cout<<"\n\t\t\t|   4    | Tim kiem sach          |";                                                            break;
                                        case 64:gotoxy(25,11);cout<<"\n\t\t\t+--------+------------------------+";                                                           break;
                                        case 5:gotoxy(25,12);cout<<"\n\t\t\t|   5    | Chinh sua danh sach    |";                                                            break;
                                        case 65:gotoxy(25,13);cout<<"\n\t\t\t+--------+------------------------+";                                                           break;
                                        case 6:gotoxy(25,14);cout<<"\n\t\t\t|   6    | Luu danh sach ra file  |";                                                            break;
                                        case 66:gotoxy(25,15);cout<<"\n\t\t\t+--------+------------------------+";                                                           break;
                                        case 7: gotoxy(25,16);cout<<"\n\t\t\t|   7    | Mo danh sach tu file   |";                                                           break;
                                        case 67:gotoxy(25,17);cout<<"\n\t\t\t+--------+------------------------+";                                                           break;
                                        case 8:gotoxy(25,18);cout<<"\n\t\t\t|   8    | Xoa sach               |";                                                            break;
                                        case 68:gotoxy(25,19);cout<<"\n\t\t\t+--------+------------------------+";                                                           break;
                                        case 9:gotoxy(25,20);cout<<"\n\t\t\t|   9    | Thoat chuong trinh     |";                                                            break;
                                        case 69:gotoxy(25,21);cout<<"\n\t\t\t+--------+------------------------+";                                                           break;
                                        case 10: gotoxy(25,3);cout<<"   Ban muon tim kiem theo: **** " ;                                                                     break;
                                        case 49:gotoxy(25,4);cout<<"\n\t\t\t+--------+------------------------+";                                                            break;
                                        case 11:     gotoxy(25,5);     cout<<"\n\t\t\t|   1    | Ma Sach                |";                                                  break;
                                        case 50: gotoxy(25,6);       cout<<"\n\t\t\t+--------+------------------------+";                                                    break;
                                        case 12:  gotoxy(25,7);     cout<<"\n\t\t\t|   2    | Ten Sach               |";                                                     break;
                                        case 51: gotoxy(25,8);   cout<<"\n\t\t\t+--------+------------------------+";                                                        break;
                                        case 13:  gotoxy(25,9);    cout<<"\n\t\t\t|   3    | Xep hang sach          |";                                                      break;   
                                        case 52:  gotoxy(25,10);   cout<<"\n\t\t\t+--------+------------------------+";                                                      break;
                                        case 14:     gotoxy(25,11);  cout<<"\n\t\t\t|   4    | Quay lai menu          |";                                                    break;
                                        case 53:   gotoxy(25,12);   cout<<"\n\t\t\t+--------+------------------------+";                                                     break;
                                      }
                             }               
                        void luachon(){                                         /* ham lua chon de su dung phim mui ten va enter */                                            
                             unsigned char nutgia='a',nut='a';
                             int tlc,maxlc,i,manglc[40];
                             fflush(stdin);
                             switch(ct){                                          /* khai bao menu cho moi mot gia tri ct khac nhau */
                                        case 0: maxlc=9; for(i=1;i<=9;i++) manglc[i]=i;break;
                                        case 1:case 2: case 3: case 4: case 5: case 7: case 8: maxlc=2; manglc[1]=98;manglc[2]=99;break;
                                        case 6: maxlc=4; manglc[1]=11;manglc[2]=12;manglc[3]=13;manglc[4]=14;break;
                                        }
                             tlc=lc=oldlc;                                       /* ban dau*/                                                       
                             tlc=lc=1;
                                
                             textcolor(11);
                             ten(manglc[lc]);
                             while (nutgia!=0xD)                              
                                        {
                                            // bat phim
                                            nutgia=getch();
                                            if (nutgia==224) nut=getch();
                                    
                                    
                                            if (nutgia==0x1B)
                                                switch (ct)
                                            {
                                                case 0:exit(0);
                                            }
                                    
                                            switch (ct)
                                            {
                                            case 0: switch (nut)
                                                    {
                                    
                                                        case 0x4B:case 0x48: lc--; break;
                                                        case 0x4D:case 0x50: lc++; break;
                                                    }
                                                    break;
                                            
                                            case 1:case 2:case 3:case 4:case 5:case 7:case 8: switch(nut)
                                                    {
                                                        
                                                     case 0x4B:   case 0x48: case 0x50:case 0x4D: lc++;break;
                                                        
                                                        
                                                    }break;
                                            case 6: switch (nut)
                                                    {
                                    
                                                        case 0x4B:case 0x48: lc--; break;
                                                        case 0x4D:case 0x50: lc++; break;
                                                    }
                                                    break;
                                                    
                                    
                                            }
                                            
                             if (lc>maxlc) lc=1;
                             if (lc<1) lc=maxlc;
                             
                             textcolor(15);ten(manglc[tlc]);
                             textcolor(11);ten(manglc[lc]);
                             
                             tlc=lc;                         /* chuan bi cho vong lap sau */
                             nut=0x61;
                             }
                             };
                  void turn(){ten(98);ten(99);                         /* khai bao ham quy lai menu chinh */
                                                         
                                    luachon();
                                    if (lc==2) exit(0);
                                    if (lc==1) {oldlc=1;mainmenu();}}
                             
                  void mainmenu()                                      /* menu chinh */
                                {
                                    system("cls");
                                    textcolor(15);
                                    ct=0;
                                    ten(59);ten(60);ten(1);ten(61);ten(2);ten(62);ten(3);ten(63);ten(4);ten(64);ten(5);ten(65);ten(6);ten(66);ten(7);ten(67);ten(8);ten(68);ten(9);ten(69);
                                    
                                    
                                    gotoxy(1,0);textbackground(LIGHTGRAY);cout<<"                           ****  QUAN LY THU VIEN DHBKHN ****                       " ;
                                    textbackground(2);
                                    gotoxy(1,24);textbackground(LIGHTGRAY);cout<<"  Thuc hien: The, Hoan, Thuong              Bo mon: Ngon Ngu Lap Trinh       ";
                                                                                        
                                    textbackground(2);
                                    luachon();
                                    switch (lc)
                                    {
                                    case 1:{ct=1;nhapsak();turn();}break;
                                    case 2:{ct=2;inra();turn();}break;
                                    case 3:{ct=5;sapxep(); turn();}break;
                                    case 4: {ct=6;system("cls");system("Color 2F");ten(10);ten(49);ten(11);ten(50);ten(12);ten(51);ten(13);ten(52);ten(14);ten(53);
                                     
                                     luachon();timkiem();if(lc==4) {oldlc=1;mainmenu();
                                                 }
                                                 ct=1;
                                                 turn();}
                                    case 5: {ct=7;chinhsua();turn();   }break;
                                    case 6: {ct=3;xuatfile();turn();}break;
                                    case 7: {ct=4;mofile();turn();}break;
                                    case 8: {ct=8;xoasak();turn();}break;
                                    case 9: exit(0);break;
                                    }
                                }
                   void viet(char *xau,int delay=15)                     /* mot so ham de lam cho bai them sinh dong */
                            {
                                int i;
                                for ( i=0 ; i<strlen(xau) ; ++i)
                                { putch(xau[i]);Sleep(delay);}
                            };
                   void gioithieu(){
                        int i;
                        
                        SetConsoleTitle("Bai tap lon - NNLT - Quan ly thu vien - GV: Nguyen Thanh Binh");
                        system("Color 2F");
                        ancontro();
                        for (i=0;i<16;i++){ system("cls"); 
                                                                                        
                                            textbackground(2);gotoxy(25,24-i); textcolor(15);cout<<"CHUONG TRINH QUAN LY THU VIEN\n\t\t\t\t TRUONG DHBKHN"; Sleep(100);
                                           }
                        gotoxy(20,13); textcolor(14);
                        viet("Bai tap lon",50);
                        viet("\tBo mon: Ngon Ngu Lap Trinh",50);
                        gotoxy(25,14); textcolor(12);
                        
                        viet("Loading ....................^^",50 );
                        
                        system("Color 2F");
                        system("cls");
                        mainmenu();
                        }

                        };
                        

                        
                        
                   
           
int main()                                                                                         /* ham main*/
{
    menu mn;
    mn.gioithieu();
    
    system("PAUSE");
    return 1;
}
     
