#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>
//#include <sys/types.h> 
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <ctype.h>
//#include <netdb.h>
int codelen(char* code) 
{ 
    int l = 0; 
    while (*(code + l) != '\0') 
        l++; 
    return l; 
} 
int fib(int n) 
{ 
    if (n <= 1) 
        return n; 
    return fib(n - 1) + fib(n - 2); 
} 

void error(const char *msg)
{
    perror(msg);
    exit(1);
}
long int p,q,n,t,flag,e,d,temp[100],j,m[100],i;
char msg[1000] = "";
int prime(long int);
void encrypt();
void decrypt();
int gcd(int a , int b);
FILE *filePointer ;
char en[100];
int freq[50];
void str_cat(char* str, char* parentcode, char add);
char abcdef[1000]="";
typedef struct node_t {
	struct node_t *left, *right;
	int freq;
	char c1;
} *node;
 
struct node_t pool[256] = {{0}};
node q1q1q1[255], *q1 = q1q1q1 - 1;
int n_nodes = 0, qend = 1;
char *code[128] = {0}, buf[1024];
 
node new_node(int freq, char c1, node a1, node b1)
{
	node n1 = pool + n_nodes++;
	if (freq) n1->c1 = c1, n1->freq = freq;
	else {
		n1->left = a1, n1->right = b1;
		n1->freq = a1->freq + b1->freq;
	}
	return n1;
}
 
/* priority queue */
void qinsert(node n1)
{
	int j1, i1 = qend++;
	while ((j1 = i1 / 2)) {
		if (q1[j1]->freq <= n1->freq) break;
		q1[i1] = q1[j1], i1 = j1;
	}
	q1[i1] = n1;
}
 
node qremove()
{
	int i1, l1;
	node n1 = q1[i1 = 1];
 
	if (qend < 2) return 0;
	qend--;
	while ((l1 = i1 * 2) < qend) {
		if (l1 + 1 < qend && q1[l1 + 1]->freq < q1[l1]->freq) l1++;
		q1[i1] = q1[l1], i1 = l1;
	}
	q1[i1] = q1[qend];
	return n1;
}
 
/* walk the tree and put 0s and 1s */
void build_code(node n1, char *s1, int len1)
{
	static char *out = buf;
	if (n1->c1) {
		s1[len1] = 0;
		strcpy(out, s1);
		code[n1->c1] = out;
		out += len1 + 1;
		return;
	}
 
	s1[len1] = '0'; build_code(n1->left,  s1, len1 + 1);
	s1[len1] = '1'; build_code(n1->right, s1, len1 + 1);
}
 
void init(const char *s1)
{
	int i1, freq[128] = {0};
	char c1[16];
 
	while (*s1) freq[(int)*s1++]++;
 
	for (i1 = 0; i1 < 128; i1++)
		if (freq[i1]) qinsert(new_node(freq[i1], i1, 0, 0));
 
	while (qend > 2) 
		qinsert(new_node(0, 0, qremove(), qremove()));
 
	build_code(q1[1], c1, 0);
}
 
void encode(const char *s1, char *out)
{
	while (*s1) {
		strcpy(out, code[*s1]);
		out += strlen(code[*s1++]);
	}
}
 
void decode(const char *s1, node t1)
{
	node n1 = t1;
	while (*s1) {
		if (*s1++ == '0') n1 = n1->left;
		else n1 = n1->right;
 
		if (n1->c1) putchar(n1->c1), n1 = t1;
	}
 
	putchar('\n');
	if (t1 != n1) printf("garbage input\n");
}
int main(int argc, char *argv[])
{	
    printf("***WELCOME TO SECURE AND FAST DATA TRANSFER CHANNEL***\n");
    printf("PLEASE SELECT YOUR ROLE FROM BELOW\n");
    printf("1.DATA SECURING\n");
    printf("2.DATA TRASMISSION\n");
    printf("3.MORE INFORMATION OR HELP\n");
    int type;
    scanf("%d",&type);
    switch(type)
    {
        case 1:
        {
    printf("FOR SECURITY WE HAVE IMPLEMENTED THE HUFFMANN CODING AND RSA ALGORITHM\n");
    printf("choose your data type which you want to secure from below:-\n");
    printf("1.TEXT\n");
    printf("2.IMAGE\n");
    int choice;
    scanf("%d",&choice);
    getchar();
    switch(choice)
    {
        case 1 : {
            int i1;
	char text[100];
	
	printf("ENTER THE TEXT YOU WANT TO BE SEND\n");
	printf("FIRST TEXT COMPRESSION WILL BE DONE\n");
        char chr[50];
        fgets(chr, 50, stdin); 
	
	const char *str = chr;
        char buf[1024];
	init(str);
	for (i1 = 0; i1 < 128; i1++)
		if (code[i1]) printf("'%c': %s\n", i1, code[i1]);
 
	encode(str, buf);
	printf("AFTER APPLYING HUFFMANN ENCODING:-\n");
	printf("encoded: %s\n", buf);
 
	//printf("decoded: ");
	//decode(buf, q1[1]);

        strcpy(msg, buf);
        /////////////////
        ////////////////
        ////////////////
        ///////////////
        printf("ENCRYPTING THE COMPRESSED MESSAGE:-");
   printf("\nENTER FIRST PRIME NUMBER\n");
 
scanf("%d",&p);
 
	flag = prime(p);
 
	if(flag==0) {
 
		printf("\nWRONG INPUT\n");
 
		
 
		exit(1);
 
	}
 
	printf("\nENTER ANOTHER PRIME NUMBER\n");
 
	scanf("%d",&q);
 
	flag=prime(q);
 
	if(flag==0||p==q) {
 
		printf("\nWRONG INPUT\n");
 
		
		exit(1);
 }
	
	for (i=0;msg[i]!=NULL;i++)
 
	m[i]=msg[i];
 
	n=p*q;
 
	t=(p-1)*(q-1);
    e = 2;
	while(e<t)
	{
	    int count = gcd(e,t);
	    if(count==1)
	    {
	        break;
	    }
	    else
	    {
	        e++;
	    }
	}
	long int k = 2;
	d = (1+(k*t))/e;
	encrypt();
	decrypt();
	printf("\n");
	printf("AFTER APPLYING HUFFAMN DECODING:-\n");
	printf("DECODED MESSAGE: ");
	decode(buf, q1[1]);
        break;
        }
case 2 : 
{
    printf("IN IMAGE PART FIRST WE ARE DOING COMPRESSION THEN REST OF THE PROCEDURES\n");
    printf("WE ARE ONLY USING .BMP IMAGE FORMAT\n");
    int i, j; 
    char path[20]; 
   printf("PLEASE ENTER THE PATH OF AN IMAGE\n");
    
  
   scanf("%[^\n]%*c", path); 
   
     char filename[200];
    sprintf( filename, path);
    int data = 0, offset, bpp = 0, width, height; 
    long bmpsize = 0, bmpdataoff = 0; 
    int** image; 
    int temp = 0; 
   
    // Reading the BMP File 
    FILE* image_file; 
      
    image_file = fopen(filename, "rb"); 
    if (image_file == NULL)  
    { 
        printf("Error Opening File!!"); 
        exit(1); 
    } 
    else
    { 
          
        // Set file position of the  
        // stream to the beginning 
        // Contains file signature  
        // or ID "BM" 
        offset = 0;  
          
        // Set offset to 2, which  
        // contains size of BMP File 
        offset = 2; 
          
        fseek(image_file, offset, SEEK_SET); 
          
        // Getting size of BMP File 
        fread(&bmpsize, 4, 1, image_file); 
          
        // Getting offset where the 
        // pixel array starts 
        // Since the information is  
        // at offset 10 from the start,  
        // as given in BMP Header 
        offset = 10;  
          
        fseek(image_file, offset, SEEK_SET); 
          
        // Bitmap data offset 
        fread(&bmpdataoff, 4, 1, image_file); 
          
        // Getting height and width of the image 
        // Width is stored at offset 18 and  
        // height at offset 22, each of 4 bytes 
        fseek(image_file, 18, SEEK_SET); 
          
        fread(&width, 4, 1, image_file); 
          
        fread(&height, 4, 1, image_file); 
          
        // Number of bits per pixel 
        fseek(image_file, 2, SEEK_CUR); 
          
        fread(&bpp, 2, 1, image_file); 
          
        // Setting offset to start of pixel data 
        fseek(image_file, bmpdataoff, SEEK_SET); 
          
        // Creating Image array 
        image = (int**)malloc(height * sizeof(int*)); 
          
        for (i = 0; i < height; i++) 
        { 
            image[i] = (int*)malloc(width * sizeof(int)); 
        } 
          
        // int image[height][width] 
        // can also be done 
        // Number of bytes in  
        // the Image pixel array 
        int numbytes = (bmpsize - bmpdataoff) / 3;  
          
        // Reading the BMP File 
        // into Image Array 
        for (i = 0; i < height; i++)  
        { 
            for (j = 0; j < width; j++)  
            { 
                fread(&temp, 3, 1, image_file); 
                  
                // the Image is a  
                // 24-bit BMP Image 
                temp = temp & 0x0000FF;  
                image[i][j] = temp; 
            } 
        } 
    } 
      
    // Finding the probability 
    // of occurence 
    int hist[256]; 
    for (i = 0; i < 256; i++) 
        hist[i] = 0; 
    for (i = 0; i < height; i++) 
        for (j = 0; j < width; j++) 
            hist[image[i][j]] += 1; 
              
    // Finding number of  
    // non-zero occurences 
    int nodes = 0; 
    for (i = 0; i < 256; i++) 
        if (hist[i] != 0) 
            nodes += 1; 
              
    // Calculating minimum probability 
    float p = 1.0, ptemp; 
    for (i = 0; i < 256; i++)  
    { 
        ptemp = (hist[i] / (float)(height * width)); 
        if (ptemp > 0 && ptemp <= p) 
            p = ptemp; 
    } 
      
    // Calculating max length 
    // of code word 
    i = 0; 
    while ((1 / p) > fib(i)) 
        i++; 
     int maxcodelen = i - 3; 
      
    // Defining Structures pixfreq 
    struct pixfreq 
    { 
        int pix, larrloc, rarrloc; 
        float freq; 
        struct pixfreq *left, *right; 
        char code[10000]; 
    }; 
      
    // Defining Structures 
    // huffcode 
    struct huffcode  
    { 
        int pix, arrloc; 
        float freq; 
    }; 
      
    // Declaring structs 
    struct pixfreq* pix_freq; 
    struct huffcode* huffcodes; 
    int totalnodes = 2 * nodes - 1; 
    pix_freq = (struct pixfreq*)malloc(sizeof(struct pixfreq) * totalnodes); 
    huffcodes = (struct huffcode*)malloc(sizeof(struct huffcode) * nodes); 
      
    // Initializing 
    j = 0; 
    int totpix = height * width; 
    float tempprob; 
    for (i = 0; i < 256; i++) 
    { 
        if (hist[i] != 0)  
        { 
              
            // pixel intensity value 
            huffcodes[j].pix = i;  
            pix_freq[j].pix = i; 
              
            // location of the node 
            // in the pix_freq array 
            huffcodes[j].arrloc = j; 
              
            // probability of occurrence 
            tempprob = (float)hist[i] / (float)totpix;  
            pix_freq[j].freq = tempprob; 
            huffcodes[j].freq = tempprob; 
              
            // Declaring the child of leaf  
            // node as NULL pointer 
            pix_freq[j].left = NULL;  
            pix_freq[j].right = NULL; 
              
            // initializing the code  
            // word as end of line 
            pix_freq[j].code[0] = '\0';  
            j++; 
        } 
    } 
      
    // Sorting the histogram 
    struct huffcode temphuff; 
      
    // Sorting w.r.t probability  
    // of occurence 
    for (i = 0; i < nodes; i++) 
    { 
        for (j = i + 1; j < nodes; j++) 
        { 
            if (huffcodes[i].freq < huffcodes[j].freq)  
            { 
                temphuff = huffcodes[i]; 
                huffcodes[i] = huffcodes[j]; 
                huffcodes[j] = temphuff; 
            } 
        } 
    } 
      
    // Building Huffman Tree 
    float sumprob; 
    int sumpix; 
    int n = 0, k1 = 0; 
    int nextnode = nodes; 
      
    // Since total number of  
    // nodes in Huffman Tree  
    // is 2*nodes-1 
    while (n < nodes - 1)  
    { 
          
        // Adding the lowest two probabilities 
        sumprob = huffcodes[nodes - n - 1].freq + huffcodes[nodes - n - 2].freq; 
        sumpix = huffcodes[nodes - n - 1].pix + huffcodes[nodes - n - 2].pix; 
          
        // Appending to the pix_freq Array 
        pix_freq[nextnode].pix = sumpix; 
        pix_freq[nextnode].freq = sumprob; 
        pix_freq[nextnode].left = &pix_freq[huffcodes[nodes - n - 2].arrloc]; 
        pix_freq[nextnode].right = &pix_freq[huffcodes[nodes - n - 1].arrloc]; 
        pix_freq[nextnode].code[0] = '\0'; 
        i = 0; 
          
        // Sorting and Updating the  
        // huffcodes array simultaneously 
        // New position of the combined node 
        while (sumprob <= huffcodes[i].freq) 
              i++; 
              
        // Inserting the new node  
        // in the huffcodes array 
        for (k1 = nodes; k1 >= 0; k1--)  
        { 
            if (k1 == i) 
            { 
                huffcodes[k1].pix = sumpix; 
                huffcodes[k1].freq = sumprob; 
                huffcodes[k1].arrloc = nextnode; 
            } 
            else if (k1 > i) 
              
                // Shifting the nodes below  
                // the new node by 1 
                // For inserting the new node 
                // at the updated position k 
                huffcodes[k1] = huffcodes[k1 - 1]; 
              
        } 
        n += 1; 
        nextnode += 1; 
    } 
      
    // Assigning Code through 
    // backtracking 
    char left = '0'; 
    char right = '1'; 
    int index; 
    for (i = totalnodes - 1; i >= nodes; i--)  
    { 
        if (pix_freq[i].left != NULL) 
            str_cat(pix_freq[i].left->code, pix_freq[i].code, left); 
        if (pix_freq[i].right != NULL) 
            str_cat(pix_freq[i].right->code, pix_freq[i].code, right); 
    } 
      
    // Encode the Image 
    int pix_val; 
    int l; 
      
    // Writing the Huffman encoded 
    // Image into a text file 
    FILE* imagehuff = fopen("encoded_image.txt", "wb"); 
    for (i = 0; i < height; i++) 
        for (j = 0; j < width; j++)  
        { 
            pix_val = image[i][j]; 
            for (l = 0; l < nodes; l++) 
                if (pix_val == pix_freq[l].pix) 
                    fprintf(imagehuff, "%s", pix_freq[l].code); 
        } 
          
    // Printing Huffman Codes 
    printf("Huffmann Codes::\n\n"); 
    printf("pixel values ->   Code\n\n"); 
    for (i = 0; i < nodes; i++) { 
        if (snprintf(NULL, 0, "%d", pix_freq[i].pix) == 2){ 
            printf("     %d      -> %s\n", pix_freq[i].pix, pix_freq[i].code); 
            strcat(abcdef,pix_freq[l].code);
            printf("     %s  \n", abcdef);
        }
        else{
            printf("    %d      -> %s\n", pix_freq[i].pix, pix_freq[i].code); 
    strcat(abcdef,pix_freq[l].code);
printf("     %s  \n", abcdef);
}
}
      
    // Calculating Average Bit Length 
    float avgbitnum = 0; 
    for (i = 0; i < nodes; i++) 
        avgbitnum += pix_freq[i].freq * codelen(pix_freq[i].code); 
    printf("Average number of bits:: %f", avgbitnum); 
    strcpy(msg, abcdef);
        /////////////////
        ////////////////
        ////////////////
        ///////////////
   printf("\nENTER FIRST PRIME NUMBER\n");
 
scanf("%d",&p);
 
    flag = prime(p);
 
    if(flag==0) {
 
        printf("\nWRONG INPUT\n");
 
        
 
        exit(1);
 
    }
 
    printf("\nENTER ANOTHER PRIME NUMBER\n");
 
    scanf("%d",&q);
 
    flag=prime(q);
 
    if(flag==0||p==q) {
 
        printf("\nWRONG INPUT\n");
 
        
        exit(1);
 }
    
    for (i=0;msg[i]!=NULL;i++)
 
    m[i]=msg[i];
 
    n=p*q;
 
    t=(p-1)*(q-1);
    e = 2;
    while(e<t)
    {
        int count = gcd(e,t);
        if(count==1)
        {
            break;
        }
        else
        {
            e++;
        }
    }
    long int k = 2;
    d = (1+(k*t))/e;
    encrypt();
    decrypt();
    break;
}
default :
{
    printf("PLEASE SELECT THE CORRECT DATA TYPE\n");
    break;
}
        
        
    }
        
            break;
        }
        /*case 2 : 
        {printf("Socket programming is a part of a separate package\n	");
        printf("Now you're a server, enter the port and the correct filename\n	");
        
		/*
            printf("FOR SENDING THE DATA WE HAVE IMPLEMENTED THE BASICS OF SOCKET PROGRAMMING\n");
            printf("PLEASE SELECT YOUR TYPE FROM BELOW:-\n");
            printf("1.SERVER\n");
            printf("2.CLIENT\n");
            int type1;
            scanf("%d",&type1);
            switch(type1)
            {
                case 1 : 
                {
                    printf("YOU ARE NOW SERVER\n");
                    int sockfd, newsockfd, portno;
     socklen_t clilen;
     char buffer[512];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");
          
          
          
          FILE *fp;
         int ch = 0;
	 char name[100];
	    printf("Enter the name with which file is to be saved");
	    scanf("%s", name);
            fp = fopen(name,"a");            
            int words;
		read(newsockfd, &words, sizeof(int));
            //printf("Passed integer is : %d\n" , words);      //Ignore , Line for Testing
          while(ch != words)
       	   {
        	 read(newsockfd , buffer , 512); 
	   	 fprintf(fp , " %s" , buffer);   
		 //printf(" %s %d "  , buffer , ch); //Line for Testing , Ignore
		 ch++;
	   }
     	printf("The file was received successfully\n");
	   printf("The new file created :innocent:");
     close(newsockfd);
     close(sockfd);
      break;
                }
                case 2 :
                {
                    printf("YOU ARE NOW CLIENT\n");
                    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[512];
    if (argc < 3)
    {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
  
        bzero(buffer,512);
        
    FILE *f;
    
    int words = 0;
    char c;
    char name[100];
    printf("Enter the name of file you want to send.");
    scanf("%s", name);
     f=fopen(name,"r");
    while((c=getc(f))!=EOF)			//Counting No of words in the file
	{	
		fscanf(f , "%s" , buffer);
		if(isspace(c)||c=='\t')
		words++;	
	}
	//printf("Words = %d \n"  , words);	//Ignore
       
      
	write(sockfd, &words, sizeof(int));
     	rewind(f);
      
            /*      fseek(f, 0L, SEEK_END);    	// tells size of the file. Not rquired for the functionality in code.
	int sz = ftell(f);				//Just written for curiosity.
	printf("Size is %d \n" , sz);
          rewind(f);  
            */
       
    /*char ch ;
       while(ch != EOF)
      {
		
		fscanf(f , "%s" , buffer);
		//printf("%s\n" , buffer);	//Ignore
		write(sockfd,buffer,512);
		ch = fgetc(f);
      }
	printf("The file was sent successfully");
    
    close(sockfd);
        break;
                }
                default :
                {
                    printf("PLEASE SELECT THE CORRECT TYPE\n");
                    break;
                }
            }
            break;
        }*/
        case 3 :
        {
           printf("*****HELP******\n");
           printf("->OUR PROJECT DEALS WITH THE FAST AND SECURE DATA TRASMISSION\n");
            printf("->FOR SECURITY WE ARE USING HUFFMAN ENCODING DECODING AND RSA ENCRYPTION DECRYPTION\n");
            printf("->AFTER THE COMPLETION OF FIRST PHASE , A FILE IS GENERATED AND GET SAVED IN YOUR FILE SYSYEM\n");
            printf("->IN SECOND PHASE , WE ARE USING SOCKET PROGRAMMING TO TRANSFER THE FILE BETWEEN TWO SYSTEMS\n");
            printf("->THEN REPEATING THE SAME PROCESS IN SYSTEM 2 ie DECRYPTION AND DECODING\n");
            printf("->THANK YOU\n");
         break;
        }
        default :
        {
            printf("FOR SOCKET PROGRAMMING WE HAVE A SEPARATE PACKAGE\n");
            printf("TWO FILES WILL BE REQUIRED, A SERVER AND A CLIENT \n");
            printf("IN THE SERVER PART WE NEED TO ENTER THE PORT NUMBER AS A COMMAND LINE ARGUMENT\n");
            printf("FOR CLIENT PART WE ENTER THE FILENAME TO BE RECIEVED \n");
        }
    }
    
        
}
int prime(long int pr) {
 
	int i;
 
	j=sqrt(pr);
 
	for (i=2;i<=j;i++) {
 
		if(pr%i==0)
 
		    return 0;
 
	}
 
	return 1;
 
}
int gcd(int a, int h)
{
    int temp;
    while(1)
    {
        temp = a%h;
        if(temp==0)
        return h;
        a = h;
        h = temp;
    }
}
void encrypt() {
 
	long int pt,ct,key=e,k,len;
 
	i=0;
 
	len = strlen(msg);
	//printf("%d",len);
 
	while(i!=len) {
 
		pt=m[i];
 
		pt=pt-96;
 
		k=1;
 
		for (j=0;j<key;j++) {
 
			k=k*pt;
 
			k=k%n;
 
		}
 
		temp[i]=k;
 
		ct=k+96;
 
		en[i]=ct;
 
		i++;
 
	}
 
	en[i]=-1;
 
	printf("\nTHE ENCRYPTED MESSAGE IS\n");
 
	for (i=0;en[i]!=-1;i++){
	printf("%c",en[i]);}
	
	/*Writing to a FILE*/
	
	filePointer = fopen("database.txt", "w") ; 
      
   
    if ( filePointer == NULL ) 
    { 
        printf( "database.txt file failed to open." ) ; 
    } 
    else
    { 
        printf("\n");  
        printf("The file is now opened.\n") ; 
          
       
        if ( strlen (  en  ) > 0 ) 
        { 
           
            fputs(en, filePointer) ;    
           // fputs("\n", filePointer); 
        }  
        fclose(filePointer) ; 
}
 
}
void decrypt() {
 
	long int pt,ct,key=d,k;
 
	i=0;
 
	while(en[i]!=-1) {
 
		ct=temp[i];
 
		k=1;
 
		for (j=0;j<key;j++) {
 
			k=k*ct;
 
			k=k%n;
 
		}
 
		pt=k+96;
 
		m[i]=pt;
 
		i++;
 
	}
 
	m[i]=-1;
 
	printf("\nTHE DECRYPTED MESSAGE IS\n");
 
	for (i=0;m[i]!=-1;i++)
 
	printf("%c",m[i]);
 
}
void str_cat(char* str, char* parentcode, char add) 
{ 
    int i = 0; 
    while (*(parentcode + i) != '\0')  
    { 
        *(str + i) = *(parentcode + i); 
        i++; 
    } 
    if (add != '2')  
    { 
        str[i] = add; 
        str[i + 1] = '\0'; 
    } 
    else
        str[i] = '\0'; 
}
