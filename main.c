#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <dirent.h>
#include <locale.h>

char ConvertToTagForSearch(char *searchtag){
	char tagforsearch[150]="[[";
	strcat(tagforsearch, searchtag);
	strcat(tagforsearch, "]]");
	return *tagforsearch;
}

char ConvertToFilenameForSearch(char *searchfilename){
	char filenameforsearch[150];
	int z=0;
	while(searchfilename[z]){
			if(isspace(searchfilename[z])){
				searchfilename[z]='_';
		}
	 		z++;
}
	strcpy(filenameforsearch, searchfilename);
	strcat(filenameforsearch, ".txt");
	return *filenameforsearch;
}

int SearchForTag(char *tfs){
	int TagExist;
	char tagarray[500][500];
	char filenamearrayfortagsearch[200][500];
	int i=0;
	
	DIR* classdirfortagsearch= opendir("C:\\Users\\Goksel_Okandan\\OneDrive\\Belgeler\\BILGISAYAR MUHENDISLIGI PROJELERIM\\ProLab Dersi Projeleri\\Proje 1 (DokuWiki Kocaeli University)\\Universite\\bolumler");
    if (classdirfortagsearch==NULL)
    {
        return 1;
    }
    
	struct dirent* classentryfortagsearch;
    classentryfortagsearch=readdir(classdirfortagsearch);
    while(classentryfortagsearch != NULL)
    {
        strcpy(filenamearrayfortagsearch[i],classentryfortagsearch->d_name);
        classentryfortagsearch=readdir(classdirfortagsearch);
        i++;
    }
    closedir(classdirfortagsearch);
    
    DIR* lessondirfortagsearch= opendir("C:\\Users\\Goksel_Okandan\\OneDrive\\Belgeler\\BILGISAYAR MUHENDISLIGI PROJELERIM\\ProLab Dersi Projeleri\\Proje 1 (DokuWiki Kocaeli University)\\Universite\\dersler");
    if (lessondirfortagsearch==NULL)
    {
        return 1;
    }
    
	struct dirent* lessonentryfortagsearch;
    lessonentryfortagsearch=readdir(lessondirfortagsearch);
    while(lessonentryfortagsearch != NULL)
    {
        strcpy(filenamearrayfortagsearch[i],lessonentryfortagsearch->d_name);
        lessonentryfortagsearch=readdir(lessondirfortagsearch);
        i++;
    }

    closedir(lessondirfortagsearch);
    
    char *allcontent = 0;
    long len=100000;
    FILE *filepoint;
    
    for (int k=0;k<=i;k++){
    	filepoint = fopen(filenamearrayfortagsearch[k],"r");
    	
    	if(filepoint)
    		allcontent = malloc(len);
    		if(allcontent)
    			fread(allcontent, 1, len, filepoint);
    		
    		fclose(filepoint);
    		
    		if(allcontent){
    			char *tagptr = strstr(tfs, allcontent);
    			
    			if(tagptr!=NULL){
    				TagExist=1;
				}
				else
				TagExist=0;
			}
}
	return TagExist;
}

int SearchForFilename(char *filenameforsearch){
	int FileExist;
	char filenamearray[200][500];
    int i=0;
    
    DIR* classdir= opendir("C:\\Users\\Goksel_Okandan\\OneDrive\\Belgeler\\BILGISAYAR MUHENDISLIGI PROJELERIM\\ProLab Dersi Projeleri\\Proje 1 (DokuWiki Kocaeli University)\\Universite\\bolumler");
    if (classdir==NULL)
    {
        return 1;
    }
    
	struct dirent* classentry;
    classentry=readdir(classdir);
    while(classentry != NULL)
    {
        strcpy(filenamearray[i],classentry->d_name);
        classentry=readdir(classdir);
        i++;
    }
    closedir(classdir);
    
    DIR* lessondir= opendir("C:\\Users\\Goksel_Okandan\\OneDrive\\Belgeler\\BILGISAYAR MUHENDISLIGI PROJELERIM\\ProLab Dersi Projeleri\\Proje 1 (DokuWiki Kocaeli University)\\Universite\\dersler");
    if (lessondir==NULL)
    {
        return 1;
    }
    
	struct dirent* lessonentry;
    lessonentry=readdir(lessondir);
    while(lessonentry != NULL)
    {
        strcpy(filenamearray[i],lessonentry->d_name);
        lessonentry=readdir(lessondir);
        i++;
    }

    closedir(lessondir);
    
    for (int i2=0;i2<=i;i++){
     		if(filenameforsearch==filenamearray[i]){
     			FileExist=1;
     			break;
			}
}
	return FileExist;
}

int SearchWithinFiles(char *searchedword){
	
}

int CheckIfOrphanForWrite(){
	
}

int main(int argc, char* argv[]){

    setlocale(LC_ALL, "Turkish");

    printf("DOKUWÝKÝ - KOCAELÝ ÜNÝVERSÝTESÝ	\n");
    printf("1. Ders Ara\n");
    printf("2. Etiket Güncelle\n");
    printf("3. Dosyaya Yaz\n");
    printf("4. Çýkýþ Yap\n");

    int islem;
    int derskodu=200;
    char aranan_kelime[500];
    char tagforsearch[500];
    char filenameforsearch[500];
    int TagExist;
    int FileExist;
    
    char eski_etiket[500];
    char yeni_etiket[500];
    char newfilename[500];
	char tempfilename[500];
	char temp2filename[500];
	char txtextension[] = ".txt";
    char yeni_dosya[500];
    char uniclasspath[] = "C:\\Users\\Goksel_Okandan\\OneDrive\\Belgeler\\BILGISAYAR MUHENDISLIGI PROJELERIM\\ProLab Dersi Projeleri\\Proje 1 (DokuWiki Kocaeli University)\\Universite\\bolumler\\";
    char unilessonpath[] = "C:\\Users\\Goksel_Okandan\\OneDrive\\Belgeler\\BILGISAYAR MUHENDISLIGI PROJELERIM\\ProLab Dersi Projeleri\\Proje 1 (DokuWiki Kocaeli University)\\Universite\\dersler\\";
    
    while (1){
        printf("Ýþlem Numarasýný Giriniz: ");
        scanf("%d", &islem);
        getchar();

        switch(islem){
            case 1:
                printf("Aramak Ýstediðiniz Kelime veya Etiket Ýsmini Giriniz: ");
                fgets(aranan_kelime,500,stdin);
                tagforsearch[500] = ConvertToTagForSearch(aranan_kelime);
                filenameforsearch[500] = ConvertToFilenameForSearch(aranan_kelime);
                TagExist = SearchForTag(tagforsearch);
                FileExist = SearchForFilename(filenameforsearch);
                
				if(TagExist==1 && FileExist==1)
                	printf("\n%s Normal Etikettir. Dosyasý ve Etiketi Vardýr.\n",aranan_kelime);
                else if (TagExist==1 && FileExist==0)
                	printf("\n%s Yetim Etikettir. Etiketi Var, Dosyasý Yoktur.\n",aranan_kelime);
                else if(TagExist==0 && FileExist==1)
                	printf("\n%s Ýstenen Etikettir. Dosyasý Var, Etiketi Yoktur.\n",aranan_kelime);
                else if(TagExist==0 && FileExist==0){
                	printf("\n%s Etiket Deðildir. Ne Dosyasý Ne Etiketi Vardýr.\n",aranan_kelime);
                	SearchWithinFiles(aranan_kelime);
            }
            break;
            
            case 2:
                printf("Hangi Etiketi Güncellemek Ýstersiniz? (Etiket Formunda Giriniz))\n");
                fgets(eski_etiket,sizeof eski_etiket,stdin);
                
                printf("Yeni Etiketi, Etiket Formunda Giriniz.");
                fgets(yeni_etiket,sizeof yeni_etiket,stdin);
                
                for(int x=0;x<=500;x++){
					tempfilename[x]=yeni_etiket[x+2];
				}
	 
	 			int tempfnlen=strlen(tempfilename)-3;
	 
	 			for(int x2=0;x2<tempfnlen;x2++){
	 				temp2filename[x2]=tempfilename[x2];
	 			}
	 			
				int y=0;
	 			while(temp2filename[y]){
	 				if(isspace(temp2filename[y])){
						temp2filename[y]='_';
					}
	 				y++;
	 			}
	
                strcpy(newfilename, temp2filename);
				strcat(newfilename, txtextension);
				
                newfilename[500] = strcat(unilessonpath, newfilename);
                yeni_dosya[500] = strcpy(yeni_dosya, unilessonpath);
				
				// OPEN NEW FILE WITH NEW FILENAME
				FILE *newfile=NULL;
				newfile=fopen(yeni_dosya,"w+");
				fprintf(newfile, "Dersin Kodu: %d\n", derskodu);
				derskodu++;
                fprintf(newfile, "Dersin Adý: %s\n", yeni_etiket);
                fprintf(newfile, "Dersin Ýçeriði: \n");
                fclose(newfile);
            break;

            case 3:
                printf("Kayýt Baþladý: \n");
                // Write To Output - Continuing
                
                FILE *out=NULL;
                out=fopen("output.txt","a+");
                
                if(out!=NULL){
                    fseek(out, 0, SEEK_END);
                    int size = ftell(out);

                    if(size==0){
                        fputs("Etiket Listesi     -    Tekrar Sayýsý\n",out);
                        
                        fputs("Yetim Etiketler\n",out);
                        // for (int orphancount=0;orphancount<=100;orphancount++)
                        	// fprintf(out,"%s\n",orphantag[orphancount][100]);
						}
                    
                    if(size!=0){
                        fputs("GÜNCEL LÝSTE\n",out);
                        fputs("Etiket Listesi     -    Tekrar Sayýsý\n",out);
                    
                        fputs("Yetim Etiketler\n",out);
                        // for (int orphancount=0;orphancount<=100;orphancount++){
                        	// fprintf(out,"%s\n",orphantag[orphancount]);
                    }
                    fclose(out);
            break;

           	case 4:
                exit(0);
            break;

            default:
                printf("Geçersiz Ýþlem Girdiniz! Lütfen Tekrar Deneyiniz.\n");
            break;
        }
    }
}
}
