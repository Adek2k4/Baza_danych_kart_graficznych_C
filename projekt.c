#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include<conio.h>

#define MAX_FILENAME_LENGTH 256

FILE *currentFile = NULL;
char currentFilename[MAX_FILENAME_LENGTH];

struct karty
{
    char marka[50];
    char model[50];
    int przepustowosc;
    int taktowanie;
    int rdzenie;
    int TDP;
    char RT[10];
};

void przegladBazy();

int isValidFormat(const char *filename)
{
    size_t len = strlen(filename);

    if (len != 9 && len != 10)
        return 0;

    if (strncmp(filename, "baza", 4) != 0)
        return 0;

    if (strcmp(filename + len - 4, ".dat") != 0)
        return 0;

    if (!isdigit(filename[4]))
        return 0;

    if (len == 10 && !isdigit(filename[5]))
        return 0;

    return 1;
}

void dodajStrukture()
{
	system("cls");
    struct karty nowaKarta;
    int k,temp;
    int dlugosc;
    
    printf("Marka: ");
    fflush(stdin);
    fgets(nowaKarta.marka, 50, stdin);
            
    dlugosc = strlen(nowaKarta.marka);
   	if(dlugosc>0 && nowaKarta.marka[dlugosc-1]=='\n')
    	nowaKarta.marka[dlugosc-1]='\0';

    printf("Model: ");
    fflush(stdin);
    fgets(nowaKarta.model, 50, stdin);
            
    dlugosc = strlen(nowaKarta.model);
   	if(dlugosc>0 && nowaKarta.model[dlugosc-1]=='\n')
    	nowaKarta.model[dlugosc-1]='\0';

    do
	{
		printf("Przepustowosc: ");
    	k=scanf("%d", &nowaKarta.przepustowosc);
    	if(k==0)
    		printf("Blad formatu!\n");
    	fflush(stdin);
	} while(k==0);

    do
	{
		printf("Taktowanie: ");
    	k=scanf("%d", &nowaKarta.taktowanie);
    	if(k==0)
    		printf("Blad formatu!\n");
    	fflush(stdin);
	} while(k==0);

    do
	{
		printf("Liczba rdzeni: ");
    	k=scanf("%d", &nowaKarta.rdzenie);
    	if(k==0)
    		printf("Blad formatu!\n");
    	fflush(stdin);
	} while(k==0);

    do
	{
		printf("TDP: ");
    	k=scanf("%d", &nowaKarta.TDP);
    	if(k==0)
    		printf("Blad formatu!\n");
    	fflush(stdin);
	} while(k==0);

    do
	{
		printf("Ray Tracing (1/0): ");
    	k=scanf("%d", &temp);
    	if(k==0)
    		printf("Blad formatu!\n");
    	fflush(stdin);
	} while(k==0 || temp>1 || temp<0);
	if(temp)
		strcpy(nowaKarta.RT,"Tak");
	else
		strcpy(nowaKarta.RT,"Nie");
	
	fclose(currentFile);
    FILE *plik;
    plik=fopen(currentFilename,"ab");
    fwrite(&nowaKarta, sizeof(struct karty), 1, plik);
    currentFile=fopen(currentFilename,"r+b");
    fclose(plik);
    
    przegladBazy();
}

void modyfikujStrukture(struct karty *karta_tab, int indeks) 
{
    int k,temp, i=indeks;
    char wybor;
    int dlugosc;
    
    system("cls");
		printf("   %-10s %-20s %-15s %-15s %-10s %-10s %-10s\n", "Marka", "Model", "Przepustowosc", "Taktowanie", "Rdzenie", "TDP", "RT");
	    printf("--------------------------------------------------------------------------------------------------------------------\n");
	    printf("->  ");
	    printf("%-10s %-20s %-15d %-15d %-10d %-10d %-10s\n", karta_tab[i].marka, karta_tab[i].model, karta_tab[i].przepustowosc, karta_tab[i].taktowanie, karta_tab[i].rdzenie, karta_tab[i].TDP, karta_tab[i].RT);
    
    printf("\nKtore pole chcesz zmodyfikowac?\n");
    printf("1. Marka\n");
    printf("2. Model\n");
    printf("3. Przepustowosc\n");
    printf("4. Taktowanie\n");
    printf("5. Liczba rdzeni\n");
    printf("6. TDP\n");
    printf("7. Ray Tracing (1/0)\n");
    wybor=getch();

    switch(wybor) 
	{
        case '1':
            printf("Marka: ");
            fflush(stdin);
            fgets(karta_tab[indeks].marka, 50, stdin);
            
            dlugosc = strlen(karta_tab[indeks].marka);
   			if(dlugosc>0 && karta_tab[indeks].marka[dlugosc-1]=='\n')
        		karta_tab[indeks].marka[dlugosc-1]='\0';
            break;
        case '2':
            printf("Model: ");
            fflush(stdin);
            fgets(karta_tab[indeks].model, 50, stdin);
            
            dlugosc = strlen(karta_tab[indeks].model);
   			if(dlugosc>0 && karta_tab[indeks].model[dlugosc-1]=='\n')
        		karta_tab[indeks].model[dlugosc-1]='\0';
            break;
        case '3':
            do
			{
				printf("Przepustowosc: ");
    			k=scanf("%d", &karta_tab[indeks].przepustowosc);
    			if(k==0)
    				printf("Blad formatu!\n");
    			fflush(stdin);
			} while(k==0);
            break;
        case '4':
            do
			{
				printf("Taktowanie: ");
    			k=scanf("%d", &karta_tab[indeks].taktowanie);
    			if(k==0)
    				printf("Blad formatu!\n");
    			fflush(stdin);
			} while(k==0);
            break;
        case '5':
            do
			{
				printf("Liczba rdzeni: ");
    			k=scanf("%d", &karta_tab[indeks].rdzenie);
    			if(k==0)
    				printf("Blad formatu!\n");
    			fflush(stdin);
			} while(k==0);
            break;
        case '6':
            do
			{
				printf("TDP: ");
    			k=scanf("%d", &karta_tab[indeks].TDP);
    			if(k==0)
    				printf("Blad formatu!\n");
    			fflush(stdin);
			} while(k==0);
            break;
        case '7':
            do
			{
				printf("Ray Tracing (1/0): ");
    			k=scanf("%d", &temp);
    			if(k==0)
    				printf("Blad formatu!\n");
    			fflush(stdin);
			} while(k==0 || temp>1 || temp<0);
			if(temp)
				strcpy(karta_tab[indeks].RT,"Tak");
			else
				strcpy(karta_tab[indeks].RT,"Nie");
            break;
        default:
            printf("Niepoprawny wybór.\n");
            break;
    }

    // Przesuniêcie wskaŸnika pliku do modyfikowanej struktury
    fseek(currentFile, indeks * sizeof(struct karty), SEEK_SET);
    // Zapisanie zmodyfikowanej struktury do pliku
    fwrite(&karta_tab[indeks], sizeof(struct karty), 1, currentFile);
    
    przegladBazy();
}


void otworzBaze()
{
    if (currentFile != NULL)
    {
        fclose(currentFile);
        currentFile = NULL;
    }

    char nazwa[15];
    printf("Podaj nazwe pliku bazy (bazaX.dat/bazaXX.dat): ");
    scanf("%s", nazwa);

    if (!isValidFormat(nazwa))
    {
        system("cls");
        printf("Niepoprawna nazwa!\n");
        return;
    }

    FILE *plik = fopen(nazwa, "r+b");
    if (plik)
    {
        strcpy(currentFilename, nazwa);
        currentFile = plik;
        system("cls");
        printf("Otwarto plik \"%s\"\n", nazwa);
    }
    else
    {
        system("cls");
        printf("Plik nie istnieje!\n");
    }
}


int fileExists(const char *filename) 
{
    FILE *file = fopen(filename, "r");
    if (file) 
    {
        fclose(file);
        return 1; // Plik istnieje
    } 
    else 
        return 0; // Plik nie istnieje
}

void utworzNowaBaze()
{
    struct karty nowaKarta;
    int k, temp, czy_nastepny, dlugosc, czy_zapis;
    char nazwa[15];

    printf("Podaj nazwe pliku nowej bazy (bazaX.dat/bazaXX.dat): ");
    scanf("%s", nazwa);

    if (!isValidFormat(nazwa))
    {
        system("cls");
        printf("Niepoprawna nazwa!\n");
        return;
    }

    if (fileExists(nazwa))
    {
        system("cls");
        printf("Plik o tej nazwie juz istnieje!\n");
        return;
    }

    FILE *file = fopen(nazwa, "w+b");
    if (!file)
    {
        system("cls");
        printf("Nie uda³o siê utworzyæ pliku %s.\n", nazwa);
        return;
    }

    system("cls");
    printf("Plik zostal utworzony.\n");

    do
    {
        printf("Czy chcesz zapisac dane do bazy? (0/1)\n");
        k = scanf("%d", &czy_zapis);
        system("cls");
        if (k == 0)
            printf("Blad formatu!\n");
        fflush(stdin);
    } while (k == 0 || czy_zapis > 1 || czy_zapis < 0);

    if (czy_zapis)
    {
        do
        {
            printf("Marka: ");
            fflush(stdin);
            fgets(nowaKarta.marka, 50, stdin);
            dlugosc = strlen(nowaKarta.marka);
            if (dlugosc > 0 && nowaKarta.marka[dlugosc - 1] == '\n')
                nowaKarta.marka[dlugosc - 1] = '\0';

            printf("Model: ");
            fflush(stdin);
            fgets(nowaKarta.model, 50, stdin);
            dlugosc = strlen(nowaKarta.model);
            if (dlugosc > 0 && nowaKarta.model[dlugosc - 1] == '\n')
                nowaKarta.model[dlugosc - 1] = '\0';

            do
            {
                printf("Przepustowosc: ");
                k = scanf("%d", &nowaKarta.przepustowosc);
                if (k == 0)
                    printf("Blad formatu!\n");
                fflush(stdin);
            } while (k == 0);

            do
            {
                printf("Taktowanie: ");
                k = scanf("%d", &nowaKarta.taktowanie);
                if (k == 0)
                    printf("Blad formatu!\n");
                fflush(stdin);
            } while (k == 0);

            do
            {
                printf("Liczba rdzeni: ");
                k = scanf("%d", &nowaKarta.rdzenie);
                if (k == 0)
                    printf("Blad formatu!\n");
                fflush(stdin);
            } while (k == 0);

            do
            {
                printf("TDP: ");
                k = scanf("%d", &nowaKarta.TDP);
                if (k == 0)
                    printf("Blad formatu!\n");
                fflush(stdin);
            } while (k == 0);

            do
            {
                printf("Ray Tracing (1/0): ");
                k = scanf("%d", &temp);
                if (k == 0)
                    printf("Blad formatu!\n");
                fflush(stdin);
            } while (k == 0 || temp > 1 || temp < 0);
            if (temp)
                strcpy(nowaKarta.RT, "Tak");
            else
                strcpy(nowaKarta.RT, "Nie");

            fwrite(&nowaKarta, sizeof(struct karty), 1, file);

            do
            {
                system("cls");
                printf("Czy wpisac nastepny rekord? (0/1)\n");
                k = scanf("%d", &czy_nastepny);
                system("cls");
                if (k == 0)
                    printf("Blad formatu!\n");
                fflush(stdin);
            } while (k == 0 || czy_nastepny > 1 || czy_nastepny < 0);

        } while (czy_nastepny);
    }

    fclose(file);
    printf("Plik zostal zapisany.\n");
}

void usunStrukture(struct karty *karta_tab, int n, int indeks)
{
	struct karty temp;
    
    for(int i=indeks; i<n-1; i++)
    {
    	temp=karta_tab[i];
    	karta_tab[i]=karta_tab[i+1];
    	karta_tab[i+1]=temp;
	}
	fclose(currentFile);
	remove(currentFilename);
	currentFile=fopen(currentFilename,"wb");
	for(int i=0; i<n-1; i++)
		fwrite(&karta_tab[i], sizeof(struct karty), 1, currentFile); 
	fclose(currentFile);
	currentFile=fopen(currentFilename,"r+b");
	przegladBazy();
}

int compareByMarka(const void *a, const void *b) 
{
    return strcmp(((struct karty *)a)->marka, ((struct karty *)b)->marka);
}

int compareByModel(const void *a, const void *b) 
{
    return strcmp(((struct karty *)a)->model, ((struct karty *)b)->model);
}

int compareByPrzepustowosc(const void *a, const void *b) 
{
    return ((struct karty *)a)->przepustowosc - ((struct karty *)b)->przepustowosc;
}

int compareByTaktowanie(const void *a, const void *b) 
{
    return ((struct karty *)a)->taktowanie - ((struct karty *)b)->taktowanie;
}

int compareByRdzenie(const void *a, const void *b) 
{
    return ((struct karty *)a)->rdzenie - ((struct karty *)b)->rdzenie;
}

int compareByTDP(const void *a, const void *b) 
{
    return ((struct karty *)a)->TDP - ((struct karty *)b)->TDP;
}

int compareByRT(const void *a, const void *b) 
{
    return strcmp(((struct karty *)a)->RT, ((struct karty *)b)->RT);
}

void zamienKolejnosc(struct karty *tablica, int liczba_struktur_w_pliku) 
{
    struct karty temp;
    int i, j;

    // Odwracanie kolejnoœci za pomoc¹ zamiany miejscami
    for (i = 0, j = liczba_struktur_w_pliku - 1; i < j; ++i, --j) 
	{
        temp = tablica[i];
        tablica[i] = tablica[j];
        tablica[j] = temp;
    }
}

void sortowaniePliku()
{
	system("cls");
    long fileSize;
    int liczba_struktur_w_pliku;
    struct karty *karta_tab;

    if (currentFile == NULL)
	{
        printf("Brak otwartego pliku.\n");
        return;
    }
    fseek(currentFile, 0, SEEK_END);
    fileSize = ftell(currentFile);
    rewind(currentFile);
    liczba_struktur_w_pliku = fileSize / sizeof(struct karty);

    if (fileSize == 0)
	{
        printf("Plik jest pusty.\n");
        return;
    }

    karta_tab = (struct karty *)malloc(liczba_struktur_w_pliku * sizeof(struct karty));
    if (karta_tab == NULL)
	{
        printf("Blad alokacji pamieci!\n");
        exit(1);
    }

    for(int i = 0; i < liczba_struktur_w_pliku; i++)
        fread(&karta_tab[i], sizeof(struct karty), 1, currentFile);

    printf("Po jakiej zmiennej chcesz sortowac?\n");
    printf("1. Marka\n");
    printf("2. Model\n");
    printf("3. Przepustowosc\n");
    printf("4. Taktowanie\n");
    printf("5. Rdzenie\n");
    printf("6. TDP\n");
    printf("7. RT\n");
    char wybor=getch();
    char wybor2;
    int rosmal=-1;
    do
    {
    	system("cls");
    	printf("Rosnaco (0), czy malejaco (1)?\n");
    	wybor2=getch();
    	if(wybor2=='0')
    		rosmal=0;
    	if(wybor2=='1')
    		rosmal=1;
	}while(rosmal>1 || rosmal<0);

    switch (wybor)
	{
        case '1':
            qsort(karta_tab, liczba_struktur_w_pliku, sizeof(struct karty), compareByMarka);
            if(rosmal)
            	zamienKolejnosc(karta_tab, liczba_struktur_w_pliku);
            break;
        case '2':
            qsort(karta_tab, liczba_struktur_w_pliku, sizeof(struct karty), compareByModel);
            if(rosmal)
            	zamienKolejnosc(karta_tab, liczba_struktur_w_pliku);
			break;
        case '3':
            qsort(karta_tab, liczba_struktur_w_pliku, sizeof(struct karty), compareByPrzepustowosc);
            if(rosmal)
            	zamienKolejnosc(karta_tab, liczba_struktur_w_pliku);
			break;
        case '4':
            qsort(karta_tab, liczba_struktur_w_pliku, sizeof(struct karty), compareByTaktowanie);
            if(rosmal)
            	zamienKolejnosc(karta_tab, liczba_struktur_w_pliku);
			break;
        case '5':
            qsort(karta_tab, liczba_struktur_w_pliku, sizeof(struct karty), compareByRdzenie);
            if(rosmal)
            	zamienKolejnosc(karta_tab, liczba_struktur_w_pliku);
			break;
        case '6':
            qsort(karta_tab, liczba_struktur_w_pliku, sizeof(struct karty), compareByTDP);
            if(rosmal)
            	zamienKolejnosc(karta_tab, liczba_struktur_w_pliku);
			break;
        case '7':
            qsort(karta_tab, liczba_struktur_w_pliku, sizeof(struct karty), compareByRT);
            if(rosmal)
            	zamienKolejnosc(karta_tab, liczba_struktur_w_pliku);
			break;
        default:
            printf("Nieprawidlowy wybor.\n");
            free(karta_tab);
            return;
    }

    rewind(currentFile);
    for (int i = 0; i < liczba_struktur_w_pliku; i++)
        fwrite(&karta_tab[i], sizeof(struct karty), 1, currentFile);

    free(karta_tab);
    system("cls");
    printf("Plik zostal posortowany.\n");
}

void przegladBazy()
{
    long fileSize;
    int liczba_struktur_w_pliku;
    struct karty *karta_tab;
    
    int start,koniec,n,wskaznik;
	char ch1,ch2;

	
		if (currentFile == NULL) 
	    {
	        printf("Brak otwartego pliku.\n");
	        return;
	    }
	    fseek(currentFile, 0, SEEK_END);
	    fileSize = ftell(currentFile);
		liczba_struktur_w_pliku=fileSize/sizeof(struct karty);
		
	    if (fileSize == 0) 
	    {
	    	system("cls");
	        printf("Plik jest pusty.\n");
	        return;
	    }
	    // Przesuniêcie wskaŸnika pliku z powrotem na pocz¹tek
	    rewind(currentFile);
	
	    karta_tab = (struct karty *)malloc(liczba_struktur_w_pliku * sizeof(struct karty));
	    if (karta_tab == NULL) 
		{
	        printf("Blad alokacji pamieci!\n");
	        exit(1);
	    }
	    
	   
	    start=0;
		koniec=19;
		n=liczba_struktur_w_pliku;
		ch1=0;
		ch2=0;
		wskaznik=0;
		if(n<=19)
			koniec=n-1;
	do{ 
		for(int i=0; i<liczba_struktur_w_pliku; i++)
			fread(&karta_tab[i], sizeof(struct karty), 1, currentFile);
    	
    	
		system("cls");
		printf("   %-10s %-20s %-15s %-15s %-10s %-10s %-10s\n", "Marka", "Model", "Przepustowosc", "Taktowanie", "Rdzenie", "TDP", "RT");
	    printf("   --------------------------------------------------------------------------------------------------------------------\n");
		for(int i=start; i<=koniec; i++)
	    {
	    	if(i==wskaznik)
	    		printf("->  ");
	    	else
	    		printf("   ");
	        printf("%-10s %-20s %-15d %-15d %-10d %-10d %-10s\n", karta_tab[i].marka, karta_tab[i].model, karta_tab[i].przepustowosc, karta_tab[i].taktowanie, karta_tab[i].rdzenie, karta_tab[i].TDP, karta_tab[i].RT);
	    }
	    printf("\nNumer rekordu: %d\n",wskaznik);
	    printf("\n\n\nB/ArrowDn Y/ArrowUp G/Home H/End Esc\n\n");
		printf("   D - dopisz nowa strukture M - modyfikuj zaznaczona strukture\n");
		printf("   S - sortuj\n");
		printf("   U - usun zaznaczona strukture Z - zakoncz przegladanie\n");
		
		ch1=getch();
		ch2=0;
		if(ch1==-32)
			ch2=getch();

		if(ch1==121 || ch2==72)//do gory
		{
			
			if(wskaznik>start)
				wskaznik--;
			else
			{
				if(start>0)
				{
					wskaznik--;
					start--;
					koniec--;
				}
			}
		}
		if(ch1==98 || ch2==80)//na dol
		{
			if(wskaznik<koniec)
				wskaznik++;
				
			else
			{
				if(koniec<n-1)
				{
					wskaznik++;
					start++;
					koniec++;
				}
			}
		}
		if((ch1==103 || ch2==71) && n>=19)//poczatek
		{
			if(n>=19)
			wskaznik=0;
			start=0;
			koniec=19;
			
		}
		if((ch1==104 || ch2==79) && n>=19)//koniec
		{
			wskaznik=n-1;
			start=n-20;
			koniec=n-1;
		}
		
		
		if(ch1==100)//D
		{
			dodajStrukture();
			break;
		}
		if(ch1==117)//U
		{
            usunStrukture(karta_tab,liczba_struktur_w_pliku, wskaznik);
            break;
		}
		if(ch1==109)//M
		{
			modyfikujStrukture(karta_tab, wskaznik);
			break;
		}
		if(ch1==115)//S
		{
			sortowaniePliku();
			przegladBazy();
			break;
		}
		if(ch1==122)//Z
			break;

	}while(ch1!=27);
	free(karta_tab);
	system("cls");
}

void usunBaze()
{
	int dlugosc,k;
	
	char nazwa[12];
	printf("Podaj nazwe pliku do usuniecia (bazaX.dat/bazaXX.dat): ");
    fflush(stdin);
    fgets(nazwa, 12, stdin);
    dlugosc = strlen(nazwa);
	if(dlugosc>0 && nazwa[dlugosc-1]=='\n')
		nazwa[dlugosc-1]='\0';

	if(isValidFormat(nazwa))
	{
		if(fileExists(nazwa) && strcmp(currentFilename, nazwa)!=0)
		{
			k=remove(nazwa);
			if(k==0)
			{
				system("cls");
				printf("Baza usunieta.\n");
				return;
				
			}
			else
			{
				system("cls");
				perror("Blad podczas usuwania.\n");
				return;
			}
		}
		else
		{
			system("cls");
			printf("Baza o nazwie \"%s\" nie istnieje lub jest otwarta.\n",nazwa);
			return;
		}
	}
	else
	{
		system("cls");
		printf("Niepoprawna nazwa pliku bazy.\n");
		return;
	}
}

void menu()
{
    printf("MENU\n");
    printf("1. Otworz baze danych\n");
    printf("2. Utworz nowa baze\n");
    printf("3. Przeglad bazy\n");
    printf("4. Sortowanie bazy\n");
    printf("5. Usun baze\n");
    printf("6. Zamknij program.\n");
    char input = getch();
    
    switch(input)
    {
        case '1':
            system("cls");
            otworzBaze();
            break;
        case '2':
            system("cls");
            utworzNowaBaze();
            break;
        case '3':
            system("cls");
            przegladBazy();
            break;
        case '4':
        	system("cls");
        	sortowaniePliku();
            break;
        case '5':
        		system("cls");
            	usunBaze();
            break;
        case '6':
            if(currentFile) 
                fclose(currentFile);
            exit(0);
        case 27:
        	if(currentFile) 
                fclose(currentFile);
            exit(0);
        default:
            system("cls");
            printf("Podaj numer (1-6).\n");
            break;    
    }        
}

int main()
{
    while (1)
        menu();
}
