// Umut Bozdag 181601016

//Stoka Final projesi

// Magazadan Ayrintilar sekmesine gidilerek oyun satin alinabilir.
// Kullanici kutuphane sekmesinden satin aldigi oyunlari oynayabilir.
// Oyuncu kendi bilgilerini ve satin aldigi oyunlari Bilgiler dosyasýnda görebilir.

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include <string.h>

int main()
{

    int n=1,MenuSecim,SatinAl,Oyun,Cuzdan,MagazaBtn,k,uzunluk=0,sayacXOX=0,MenuyeDonus,sayacSNAKE=0,sayacTKM=0,ParaYukle,ParaMiktar,sayacGiris=5,KutuphaneyeDon;
    int c,BilgilerimiGor,uzunlukNo,sayacKullanici=0,sayacSifre=0,BilgileriGir;
    char isim[50],soyad[50],eposta[50],telNo[50],yas[50];
    float Para=0,XOX=30,SNAKE=50,TKM=30;
    void cikis_Yap(); void renk_Degistir();  void giris_Yap(); void Bilgiler();
   void yazdirSNAKE();void yazdirXOX();void yazdirTKM();
  
   
    
    struct user{
    char KullaniciAdi[10];
    char Sifre[10];
}*sKullanici; // Kullanici sifresi


    renk_Degistir();
printf("\t\t\t\t\t\t\tSaat:%s\n\t\t\t\t\t\t\tTarih:%s\n\n\n\n",__TIME__,__DATE__);

            FILE *fp;
    char aKullanici[10], pwd[10];

    sKullanici=(struct user *)malloc(sizeof(struct user));
				
    printf("\t\t\t\t1->Giris yapiniz\n\t\t\t\t2->Yeni hesap olustur\n\n\n");
    printf("\t\t\t\tSeciniz:");
    scanf("%d",& k);

    while(k<1 || k>2){
        printf("\t\t\t\tLutfen gecerli bir islem seciniz:");
        scanf("%d",&k);
    }

    switch(k){
        case 1:

            do{

            if ( ( fp=fopen("user.dat", "r+")) == NULL) {
                if ( ( fp=fopen("user.dat", "w+")) == NULL) {
                    printf ("Dosya acilamadi!\n");
                    exit ( 1);
                }
            }
            printf("\t\t\t\tKullanici adi: ");
            scanf("%9s",aKullanici);
            printf("\t\t\t\tSifre: ");
            scanf("%9s",pwd);
            while ( fread (sKullanici, sizeof(struct user), 1, fp) == 1) {  // Dosyadan bilgileri okur
                if( strcmp ( sKullanici->KullaniciAdi, aKullanici) == 0) { // Kullanici adi karsilastirmasi
                    printf ("Kullanici adi eslesti\n\a"); sayacKullanici++;
                    if( strcmp ( sKullanici->Sifre, pwd) == 0) {  // Sifre karsilastirmasi
                        printf ("Sifre eslesti\n\n\a"); sayacSifre++;

                    }
                }
            }
            if(sayacKullanici>0 && sayacSifre>0){
            	
                        system("cls");
                        printf("\n\t\t\tBasariyla giris yapildi!\n\a");
                        BilgileriGir=1;
                        goto MenuyeDon; // Giris yapildiysa Ana Menuye git
                        
                        }
                        else {
           printf("\n\t\t\tYanlis giris, Tekrar deneyin!(%d Hakkiniz kaldi!)\n\n\a", 5-n);
            getch();

            n++;
            }

             while(n>5){
          printf("\nGiris hakkiniz doldu!\a");
          exit(EXIT_SUCCESS);
          }

            }while(n<=5);

 break;
        case 2:
                if ( ( fp=fopen("user.dat", "a+")) == NULL) {
                    if ( ( fp=fopen("user.dat", "w+")) == NULL) {
                        printf ("Dosya acilamadi!\n");
                        exit ( 1);
                    }
                }
                printf("\t\t\tBir Kullanici Adi Olusturunuz: ");
                scanf("%9s",sKullanici->KullaniciAdi);  // Kullanici adi olusturur
                printf("\t\t\tBir Sifre Olusturunuz: "); // Sifre olusturur
                scanf("%9s",sKullanici->Sifre);
                fwrite (sKullanici, sizeof(struct user), 1, fp); // Dosyaya yazar
                
                
            break;
    }
    free ( sKullanici);
    fclose(fp);

                //////////// KULLANICI BILGILERI //////////////
                

        Bilgiler:
        	
        	

printf("\n Oncelikle Cuzdaniniza para yukleyebilmeniz icin sizden bilgi almamiz gerekli!\n\n");
printf("\t\tBilgilerinizi girmek icin 1'e basiniz:");
scanf("%d",&BilgileriGir);

FILE* dosya;
dosya = fopen("Bilgiler.txt","w"); // Ileride dosyanin bos olup olmadigina bakmak icin programin basinda dosyayi olusturduk
fclose(dosya);

if(BilgileriGir ==1){
    fflush(stdin);
    printf("Isminiz:"); gets(isim);
    printf("Soyadiniz:"); gets(soyad);
    printf("Yasiniz:"); gets(yas);
    printf("E-postaniz:"); gets(eposta);
    printf("Telefon numaraniz:"); gets(telNo);

    FILE *dosya;

dosya = fopen("Bilgiler.txt","w");

fprintf(dosya,"Isim:%s\nSoyad:%s\nYas:%s\nE-posta:%s\nTelefon No:%s\n",isim,soyad,yas,eposta,telNo);  // Alinan bilgileri dosyaya yazar
fclose(dosya);

}

else {
		system("cls");
    printf("\nBilgilerinizi girmediginiz icin cuzdaniniza para yukleyemezsiniz!\n(Ileride cuzdan sekmesinden bilgilerinizi girebilirsiniz!)\n\a");
}

               /////////////// ANA MENU //////////////////


       printf("\n\n\t\t\tSTOKA'ya Hos geldiniz!\n\a");


       MenuyeDon:

       printf("\n\n\t\t\t\t\t\t\tSaat:%s\n\t\t\t\t\t\t\tTarih:%s\n\n",__TIME__,__DATE__);
       printf("\n\t\t\t_-_-_-_-_- ANA MENU _-_-_-_-_-\n\n");
       printf("\t\t\t---------------------------\n");
       printf("\a");
       printf("\t\t\t1->MAGAZA\n\t\t\t2->KUTUPHANEME GIT\n\t\t\t3->CUZDANIMI GORUNTULE\n\t\t\t4->BILGILERIMI GORUNTULE\n\t\t\t5->CIKIS YAP\n");
		printf("\t\t\t---------------------------\n");
       
       printf("\t\t\tLutfen secim yapiniz:");
       scanf("%d",&MenuSecim);

       while(MenuSecim<1 || MenuSecim>5){

        printf("\t\t\tLutfen gecerli islem seciniz:");
        scanf("%d",&MenuSecim);

       }

       switch(MenuSecim){

       case 1:

          		 /////////////////////////////// MAGAZA /////////////////////////
			

                system("cls");
                MagazayaDon:
               printf("\t\t\t\t\t\t\tSaat:%s\n\t\t\t\t\t\t\tTarih:%s\n\n",__TIME__,__DATE__);
            printf("\t\t\t***********************************\n");
			  printf("\n\t\t\tMAGAZA'ya hos geldiniz!\n\n\a"); 
               printf("\t\t\t***********************************\n\n");
              printf("\n\t\t\t<<<MAGAZADAKI OYUNLAR>>>\n");
              printf("\n\t\t\t1->XOX(Ayrintilar icin 1)\n\n\t\t\t2->SNAKE(Ayrintilar icin 2)\n\n\t\t\t3->TAS KAGIT MAKAS(Ayrintilar icin 3)\n\n");
              printf("\t\t\tMENU icin 0'a basiniz\n\n");
				printf("\t\t\t------------------------\n");
                printf("\t\t\tSeciniz:");
              scanf("%d",&MagazaBtn);
              
              while(MagazaBtn<0 || MagazaBtn>3){
              	printf("\t\t\tLutfen gecerli islem seciniz:");
              	scanf("%d",&MagazaBtn);
			  }

              if(MagazaBtn==0){
              goto MenuyeDon;  // Menuye don

              }
              if(MagazaBtn==1){ 

                system("cls"); // Ekrani temizle

                ////////////// XOX //////////////

                printf("KONU\n\n XOX, Iki oyuncuyla oynanir. Kagida karsilikli dort cizgi cizilir ve ilk oyuncu karelerden birine bir X, oburu ise baska bir kareye bir O koyar. Oyun boylece surer ve oyuncular dikey, yatay ya da capraz sirada uc carpi ya da uc sifir elde etmeye calisirlar.\n\n");
                printf("UCRET:%.2f TL\nKULLANICI INCELEMELERI:Son derece olumlu\nCIKIS TARIHI: 28 Nisan 2015\nETIKETLER:Strateji\n\n",XOX);
                printf("XOX'u satin almak icin 1'e\nMagazaya donmek icin 0'a basiniz.\n\n");

                printf("Seciniz:");
                scanf("%d",&SatinAl);

                while(SatinAl!=1 && SatinAl!=0){
                    printf("Lutfen gecerli islem seciniz:");
                    scanf("%d",&SatinAl);
                }

                if(SatinAl==0){
                    goto MagazayaDon; // Magazaya Don
                }
                    // XOX'u Satin al //

                while(SatinAl==1 && Para>=30){

                sayacXOX++;

                yazdirXOX(); // Oyun satin alindiginda dosyaya yazar

                    while(sayacXOX>1){

                        printf("\n\n\nBU OYUN SIZDE ZATEN MEVCUT!\n\n\a");
                        goto MagazayaDon;
                        system("cls");
                    }

                    printf("\nXOX satin alindi!\a\nKalan paraniz=%.2f\n\n",Para-XOX);
                    Para = Para-XOX;

                    goto MenuyeDon;


                }

                    while(Para<30){
                    printf("Cuzdaninizda yeterli para yok!\a\nCuzdanina gitmek icin 0'a bas\n");
                    scanf("%d",&Cuzdan);
                    if(Cuzdan == 0){
                        goto CuzdanGit;
                    }

                }

                }

                    ///////////////	SNAKE //////////////

                if(MagazaBtn==2){
                        system("cls");

                    printf("KONU\n\nOyunda oyuncunun yon tuslariyla kontrol ettigi bir yilan ve her seferinde\nekranin farkli yerlerinde cikan yildizlar vardir. Oyuncu bu yildizlari yiyerek\nbuyur ve eger kendine dokunursa oyun sona erer.\n\n\n");
                    printf("UCRET:%.2f TL\nKULLANICI INCELEMELERI:Olumlu\nCIKIS TARIHI: 11 Kasim 1996\nETIKETLER:Simulasyon,Arcade\n\n",SNAKE);
                    printf("SNAKE'yi satin almak icin 1'e\nMagazaya donmek icin 0'a basiniz.\n");

                    printf("Seciniz:");
                    scanf("%d",&SatinAl);

                    while(SatinAl!=1 && SatinAl!=0){
                    printf("Lutfen gecerli islem seciniz:");
                    scanf("%d",&SatinAl);
                }

                    if(SatinAl==0){
                    goto MagazayaDon; // Magazaya Don
                }

                      while(SatinAl==1 && Para>=50){ // Snakeyi satin al



                sayacSNAKE++;

                    yazdirSNAKE(); // Oyun satin alindiginda dosyaya yazar

                    while(sayacSNAKE>1){
                        printf("\n\n\nBU OYUN SIZDE ZATEN MEVCUT!\n\n\a");
                        goto MagazayaDon;
                        system("cls");
                    }

                    printf("SNAKE satin alindi!\a\nKalan paraniz=%.2f\n\n",Para-SNAKE);
                    Para = Para - SNAKE;

                    goto MenuyeDon;

                }

                while(Para<50){
                    printf("Cuzdaninizda yeterli para yok!\a\nCuzdanina gitmek icin 0'a bas\n");
                    scanf("%d",&Cuzdan);

                    if(Cuzdan==0){
                        goto CuzdanGit;
                    }


                }

              }

                				////////////// TKM //////////////
                				
              if(MagazaBtn==3){

                    system("cls");

                printf("\nKONU\n\n");
                printf("Tas-kagit-makas, genellikle iki oyuncuyla ve uc durumdan birinin secilmesiyle\noynanan bir el oyunudur.Tas makasi, makas kagidi, kagit da tasi yener.\nEger oyuncular ayni durumu secerse oyun berabere biter.\n\n");
                printf("UCRET:%.2f TL\nKULLANICI INCELEMELERI:Olumlu\nCIKIS TARIHI: 15 Ekim 2008\nETIKETLER:Arcade,Hand game\n\n",TKM);
                printf("TAS KAGIT MAKAS'i satin almak icin 1'e\nMagazaya donmek icin 0'a basiniz.\n");

                printf("Seciniz:");
                scanf("%d",&SatinAl);

                while(SatinAl!=1 && SatinAl!=0){
                    printf("Lutfen gecerli islem seciniz:");
                    scanf("%d",&SatinAl);
                }

                if(SatinAl==0){
                    goto MagazayaDon; // Magazaya Don
                }

                while(SatinAl==1 && Para>=30){ // TKM'yi satin al

                sayacTKM++;

                yazdirTKM(); // Oyun satin alindiginda dosyaya yazar

                    while(sayacTKM>1){
                        printf("\n\n\nBU OYUN SIZDE ZATEN MEVCUT!\n\n\a");
                        goto MagazayaDon;
                        system("cls");
                    }

                    printf("TAS KAGIT MAKAS satin alindi!\a\nKalan paraniz=%.2f\n\n",Para-TKM);
                    Para = Para - TKM;

                    goto MenuyeDon;


                }

                while(Para<30){
                    printf("Cuzdaninizda yeterli para yok!\a\nCuzdanina gitmek icin 0'a bas\n");
                    scanf("%d",&Cuzdan);

                    if(Cuzdan==0){
                        goto CuzdanGit;
                    }

                }



              }
              break;

            /////////////////// KUTUPHANE ///////////////////

          case 2:

            KutuphaneDon:

                system("cls");

              printf("\t\t\t\t\t\t\tSaat:%s\n\t\t\t\t\t\t\tTarih:%s",__TIME__,__DATE__);

              printf("\n\n\n\n\t\t\t***** KUTUPHANENIZE Hos geldiniz! *****\n\n\n\a\t\t\t<<KUTUPHANEMDEKI OYUNLAR>>\n\n\n");
              printf("\t\t\t-------------------------------------------\n");

                printf("\t\t\tXOX(Oynamak icin 1'e basiniz...)\n\n");

                printf("\t\t\tSNAKE(Oynamak icin 2'ye basiniz...)\n\n");

                printf("\t\t\tTAS KAGIT MAKAS(Oynamak icin 3'e basiniz...)\n\n");

                printf("\t\t\tMenuye donmek icin 0'a basiniz...\n\n");
				printf("\t\t\t-------------------------------------------\n");
                printf("\t\t\tSeciniz:");
                scanf("%d",&Oyun);

                while(Oyun<0 || Oyun>3){
                    printf("\t\t\tLutfen gecerli islem seciniz:");
                    scanf("%d",&Oyun);
                }

                if(sayacXOX>=1 && Oyun==1){
                        printf("\a");
                        
                    //////// XOX KODLARI ////////

	int oyuncu = 0;
	int kazanan = 0;
	int secim = 0;
	int satir = 0;
	int sutun = 0;
	int line = 0;
	int i;

	char board [3][3] = {                   
				 {'1','2','3'},
				 {'4','5','6'},   // Tabloyu olusturma
				 {'7','8','9'}
						};

	for (i = 0; i<9 && kazanan==0; i++)
	{
		printf("\n\n");
		printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);				
		printf("---|---|---\n");  
		printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);     // Her seferinde tabloyu yenileme
		printf("---|---|---\n");
		printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

		oyuncu = i%2 + 1;

		do
		{
			printf("\nOyuncu %d, Lutfen %c'yi yerlestirmek istediginiz "
				"kareyi secin: ",
				oyuncu,(oyuncu==1)?'X':'O');
			scanf("%d", &secim);


			satir = --secim/3;
			sutun = secim%3;
		}while(secim<0 || secim>9 || board [satir][sutun]>'9');

		board[satir][sutun] = (oyuncu == 1) ? 'X' : 'O';


		if((board[0][0]==board[1][1] && board[0][0]==board[2][2]) ||
		   (board[0][2]==board[1][1] && board[0][2]==board[2][0]))
		   kazanan = oyuncu;
		else
			for(line = 0; line <=2; line++)
				if((board[line][0]==board[line][1] && board[line][0]==board[line][2])||
					(board[0][line]==board[1][line] && board[0][line]==board[2][line]))
					kazanan = oyuncu;


	}

		printf("\n\n");
		printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
		printf("---|---|---\n");
		printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
		printf("---|---|---\n");
		printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);


		if(kazanan==0)
			printf("Oyun BERABERE\n");
		else
			printf("Oyuncu %d KAZANDI\n", kazanan);

			printf("Kutuphaneye donmek icin 0'a basiniz:"); scanf("%d",&KutuphaneyeDon);
			if(KutuphaneyeDon==0){
                goto KutuphaneDon;
			}
			

    }

            else if(sayacSNAKE>=1 && Oyun == 2){


                    ////////////////////// SNAKE KODLARI ////////////////////

                    system("cls");
                    printf("\a");

int saha[80][23]={0};
int k,l;
int kuyrukSutun[300];
int kuyrukSatir[300];
char Tekrar;



void gotoxy(short x, short y) {
	HANDLE hConsoleOutput;
	COORD Cursor_Pos = {x-1, y-1};

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}



void cerceve(int x1,int y1,int x2,int y2,int tip)
{
    int i;
    for(i=x1;i<=x2;i++)
    {
        saha[i][y1]=tip;
        saha[i][y2]=tip;
    }

    for(i=y1;i<=y2;i++)
    {
        saha[x1][i]=tip;
        saha[x2][i]=tip;
    }
}

void ekranYaz()
{
    int x,y;
    for(x=0;x<80;x++)
    {
        for(y=0;y<23;y++)
        {
            gotoxy(x+1,y+1);
            if(saha[x][y]==2)
            {
                printf("%c",177);
            }
        }
    }

}


int randomAta()
{
    srand(time(NULL));
    k=4+rand()%65; //Cerceve icerisinde random yem olustur
    l=4+rand()%15;

}


    TekrarOyna:

    randomAta();
    cerceve(0,0,79,22,2);
    ekranYaz(); // Cerceve olusturma
    int sx=40,sy=12;
    unsigned char tus;
    int dy=0;
    int dx=0;
    int a=0;
    int i;
    int devam=1;

    do
    {

        if(kbhit()) // Tusa basma kontrolu
        {
            tus=getch();
            if(tus==224)
            {
                tus=getch();
                switch(tus)
                {
                    case 72: dy=-1; dx=0; // Yukari yon tusu
                        break;
                    case 80: dy=1; dx=0; // Asagi yon tusu
                        break;
                    case 77: dx=1; dy=0; // Sag yon tusu
                        break;
                    case 75: dx=-1; dy=0; // Sol yon tusu
                }
            }

        }

        sx=sx+dx;
        sy=sy+dy;
        if(sx>78)
            sx=2;
        if(sx<2)
            sx=78;
        if(sy>22)
            sy=2;
        if(sy<2)
            sy=22;

        kuyrukSutun[0]=sx;
        kuyrukSatir[0]=sy;

        for(i=1;i<=a;i++)
        {
            if(sx==kuyrukSutun[i] && sy==kuyrukSatir[i])
            {
                gotoxy(sx,sy);printf("--YANDINIZ--");

                getch();
                devam=0;

            }
        }


        gotoxy(sx,sy);printf("*");
        for(i=0;i<=a;i++)
        {
            gotoxy(kuyrukSutun[i],kuyrukSatir[i]);printf("ß"); // Oyuncu yem yediginde yilani buyult
        }

        if(sx==k && sy==l)
         {
             randomAta();
             a++;
             gotoxy(2,2);printf("Puan: %d",a); // Puani guncelle
         }
         gotoxy(k,l);printf("*"); // Yem sekli

        Sleep(60);
        gotoxy(sx,sy);printf(" ");
        for(i=0;i<=a;i++)
        {
            gotoxy(kuyrukSutun[i],kuyrukSatir[i]);printf(" ");
        }

        for(i=a;i>0;i--)
        {
            kuyrukSutun[i]=kuyrukSutun[i-1];
            kuyrukSatir[i]=kuyrukSatir[i-1];

        }

    } while (devam==1);

    printf("Tekrar oynamak ister misiniz?(E/H):");
                scanf("%s",&Tekrar);
                if(Tekrar == 'E'){
                    printf("\a");
                    system("cls");
                    goto TekrarOyna;
                }

                else {
                        system("cls");
                    goto KutuphaneDon;
                }


                }

                else if(sayacTKM>=1 && Oyun==3){
                	
                    //////////////// TKM KODLARI ///////////////
                    
                printf("\a");

int Bilgisayar,Oyuncu,bilgisayarSecim=0,oyuncuSecim=0,tekrar;



srand(time(NULL));
Bilgisayar = 1+rand()%3;

do{
    system("cls");
printf("1-Tas\n");
printf("2-Kagit\n");
printf("3-Makas\n\n");
printf("Seciniz:");
scanf("%d",&Oyuncu);

while(Oyuncu<1 || Oyuncu>3){
    printf("Lutfen gecerli islem seciniz:");
    scanf("%d",&Oyuncu);
}


if(Bilgisayar==1 && Oyuncu ==1){
    printf("Tas ve Tas, Berabere!\n");

}

else if(Bilgisayar==2 && Oyuncu == 2){
    printf("Kagit ve Kagit, Berabere!\n");

}

else if(Bilgisayar == 3 && Oyuncu == 3){
    printf("Makas ve Makas, Berabere!\n");
}

else if(Bilgisayar == 1 && Oyuncu == 2){
    oyuncuSecim++;
    printf("Kagit Tasi sarar, Kazandiniz!\n");
    printf("Bilgisayar : %d \n",bilgisayarSecim);
			printf("Sen : %d \n",oyuncuSecim);

}

else if(Bilgisayar == 2 && Oyuncu == 1){
    bilgisayarSecim++;
    printf("Kagit Tasi sarar, Kaybettin!\n");
    printf("Bilgisayar : %d \n",bilgisayarSecim);
    printf("Sen : %d \n",oyuncuSecim);

}

else if(Oyuncu == 3 && Bilgisayar == 1) {
			bilgisayarSecim+=1;
			printf("Tas Makasi Kirar , Kaybettin.\n");
			printf("Bilgisayar : %d \n",bilgisayarSecim);
			printf("Sen : %d \n",oyuncuSecim);
}

else if(Bilgisayar == 3 && Oyuncu == 1) {
			oyuncuSecim+=1;
			printf("Tas Makasi Kirar , Kazandiniz.\n");
			printf("Bilgisayar : %d \n",bilgisayarSecim);
			printf("Sen : %d \n",oyuncuSecim);
		}

else if(Bilgisayar == 3 && Oyuncu == 2) {
			bilgisayarSecim+=1;
			printf("Makas Kagiti Keser , Kaybettiniz.\n");
			printf("Bilgisayar : %d \n",bilgisayarSecim);
			printf("Sen : %d \n",oyuncuSecim);
		}

		else if(Oyuncu == 3 && Bilgisayar == 2) {
			oyuncuSecim+=1;
			printf("Makas Kagiti Keser , Kazandiniz.\n");
			printf("Bilgisayar : %d \n",bilgisayarSecim);
			printf("Sen : %d \n",oyuncuSecim);

		}



		printf("Tekrar oynamak icin 1'e basiniz\nKutuphaneye donmek icin 0'a basiniz\n\nSeciniz:");
		scanf("%d",&tekrar);
		printf("\a");

		srand(time(NULL));
        Bilgisayar = 1+rand()%3;

}while(tekrar == 1);


printf("Program kapatildi..\a\a");

goto KutuphaneDon;

                }

               else if(Oyun==0){
                    system("cls"); // Ekrani temizle
                    goto MenuyeDon; // Menuye git
                }


                else {

                system("cls");
                printf("\n\nBu oyuna sahip degilsiniz!\n\n\n\a");
                printf("\nMAGAZAYA YONLENDIRILIYORSUNUZ...\n");
                goto MagazayaDon;
                }

                break;


            case 3:
				
                 CuzdanGit:
                 CuzdanDon:
                 system("cls");  

           printf("\t\t\t\t\t\t\tSaat:%s\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tTarih:%s\n",__TIME__,__DATE__);




                    printf("\n\n\t\t\t<<CUZDANINA Hos geldin %s!>>\n\n\a",isim);
                    printf("\t\t\tSuanki bakiyeniz:%.2f\n\n",Para);
                    printf("\t\t\tCuzdaniniza para yuklemek icin 1'e\n\t\t\tMenuye donmek icin 0'a basiniz\n\n");
						
						FILE *dosya;
						int boyut;
						
						dosya=fopen("Bilgiler.txt","r"); 
                         if (dosya != NULL) {
    				fseek (dosya, 0, SEEK_END);
   					 boyut = ftell(dosya);  // Dosyanin boyutunu aldik

   		 if (boyut <= 0) {  // Dosyanin bos olup olmadigini kontrol ettik
    	   goto Bilgiler;
    			}
			}
						
						fclose(dosya);
						
                        printf("\t\t\t-----------------------------\n");
                    printf("\t\t\tSeciniz:");
                    scanf("%d",&ParaYukle);

                  while(ParaYukle!=1 && ParaYukle!=0){
                    printf("\a");

                    printf("\t\t\tLutfen gecerli islem giriniz:");
                    scanf("%d",&ParaYukle);

                  }
                    if(ParaYukle==1){

                        system("cls");
                        printf("\a");

                        printf("\t\t\t\t\t\t\tSaat:%s\t\t\t\t\t\t\t\t\tTarih:%s\n",__TIME__,__DATE__);


                        printf("\t\t\tSuanki bakiyeniz:%.2f\n\n",Para);
                        printf("\t\t\tCuzdaniniza ne kadar para yuklemek istiyorsunuz?\n\t\t\t1-10,00 TL\n\t\t\t2-20,00 TL\n\t\t\t3-50,00 TL\n\t\t\t4-100,00 TL\n\t\t\t5-200,00 TL\n\n");

                        printf("\t\t\tSeciniz:");
                        scanf("%d",&ParaMiktar);

                        while(ParaMiktar<1 || ParaMiktar>5){
                            printf("Lutfen gecerli islem giriniz:");
                            scanf("%d",&ParaMiktar);
                        }

                        switch(ParaMiktar){

                        case 1:Para += 10;
                            printf("\t\t\tYeni bakiyeniz=%.2f\n\a",Para);
                            goto CuzdanDon;
                            break;

                         case 2: Para +=20;
                         printf("\t\t\tYeni bakiyeniz=%.2f\n\a",Para);
                         goto CuzdanDon;
                         break;

                         case 3:Para+=50;
                         printf("\t\t\tYeni bakiyeniz=%.2f\n\a",Para);
                         goto CuzdanDon;
                         break;

                        case 4:Para+=100;
                         printf("\t\t\tYeni bakiyeniz=%.2f\n\a",Para);
                         goto CuzdanDon;
                         break;

                         case 5:Para+=200;
                         printf("\t\t\tYeni bakiyeniz=%.2f\n\a",Para);
                         goto CuzdanDon;
                         break;
                        }

                    }

                    if(ParaYukle == 0){
                        goto MenuyeDon;
                    }

                    case 4:

                        Bilgiler();



printf("\nMenuye donmek icin 0'a basiniz:");
scanf("%d",&MenuyeDonus);

if(MenuyeDonus == 0){
    goto MenuyeDon;
}
                    case 5:
                    cikis_Yap();
}



return 0;
}

void cikis_Yap(){
system("exit");
}

void renk_Degistir(){
system("COLOR F4");
}

void giris_Yap(){

    struct user{
    char KullaniciAdi[10];
    char Sifre[10];
}*sKullanici;

FILE *fp;
    char aKullanici[10], pwd[10];int i;char c;

if ( ( fp=fopen("user.dat", "r+")) == NULL) {
                if ( ( fp=fopen("user.dat", "w+")) == NULL) {
                    printf ("Dosya acilamadi!\n");
                    exit ( 1);
                }
            }
            printf("Kullanici adi: ");
            scanf("%9s",aKullanici);
            printf("Sifre: ");
            scanf("%9s",pwd);
            while ( fread (sKullanici, sizeof(struct user), 1, fp) == 1) {
                if( strcmp ( sKullanici->KullaniciAdi, aKullanici) == 0) {
                    printf ("Kullanici adi eslesti\n");
                    if( strcmp ( sKullanici->Sifre, pwd) == 0) {
                        printf ("Sifre eslesti\n");
                        
                    }
                }
            }
}

void Bilgiler(){

system("cls");

FILE *dosya;
int c;

 dosya=fopen("Bilgiler.txt","r");


           if(dosya==NULL){
           	printf("Herhangi bir bilgi girmediniz!");
		   }
    			
    			do{
    c=fgetc(dosya);
    if(c!=EOF){
        putchar(c);
    }
}while(c!=EOF);

fclose(dosya);

}
    			
			
void yazdirSNAKE(){

FILE *dosya;
                dosya = fopen("Bilgiler.txt","a");

            fprintf(dosya,"\nSNAKE");

        fclose(dosya);

}
void yazdirXOX(){

FILE *dosya;
                dosya = fopen("Bilgiler.txt","a");

            fprintf(dosya,"\nXOX");

        fclose(dosya);

}
void yazdirTKM(){

FILE *dosya;
                dosya = fopen("Bilgiler.txt","a");

            fprintf(dosya,"\nTKM");

        fclose(dosya);

}
