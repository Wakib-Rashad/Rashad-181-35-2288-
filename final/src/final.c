#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_READ_ERROR -1
#define FILE_WRITE_ERROR -2
#define MAX_CMD_OPT 7
#define CMD_OPT_IN_FILE "-i"
#define CMD_OPT_IN_POS 1
#define CMD_OPT_IN_VAL_POS 2
#define CMD_OPT_OUT_FILE "-o"
#define CMD_OPT_OUT_POS 3
#define CMD_OPT_OUT_VAL_POS 4
#define CMD_OPT_IN_SIZE "-s"
#define CMD_OPT_SIZE_POS 5
#define CMD_OPT_SIZE_VAL_POS 6
#define ARRAYSIZE(x) (sizeof(x) / sizeof((x)[0]))
#define ASC 1
#define DESC 2

int readIntArrayFromFile(const char *inputFilePath, int dataBuffer[], int dataBufferSize);
int writeIntArrayToFile(const char *outputFilePath, int dataBuffer[], int dataBufferSize);
void bubbleSortIntArray(int unsortedArray[], size_t arraySize, int sortOrder);
int binarySearch(int *p,int min,int max,int srch);
void linearSearch(int *p,int srch);

/* Declare your function(s) below*/

/* End of function(s) declaretion */
// int dataBuffer[1450];
int retn=0;
int main(int argc, char const *argv[])
{
    if (argc != MAX_CMD_OPT)
    {
        printf("usage: %s -i input_filename -o output_filename -s input_data_size\n", argv[0]);
        exit(1);
    }
    else
    {
        //printf("%s - %s - %s - %s - %s - %s\n",argv[1],argv[2],argv[3],argv[4],argv[5],argv[6]);
        if ((strcmp(argv[CMD_OPT_IN_POS], "-i") == 0) &&
            (strcmp(argv[CMD_OPT_OUT_POS], "-o") == 0) &&
            ((strcmp(argv[CMD_OPT_SIZE_POS], "-s") == 0)))
        {
            if ((strlen(argv[CMD_OPT_IN_VAL_POS]) > 0) && (strlen(argv[CMD_OPT_OUT_VAL_POS]) > 0))
            {
                const char *inputFilePath = argv[CMD_OPT_IN_VAL_POS];
                const char *outputFilePath = argv[CMD_OPT_OUT_VAL_POS];
                char *p;
                int i;
                int size = strtol(argv[CMD_OPT_SIZE_VAL_POS], &p, 10);
                if (size > 0)
                {
                    int dataBuffer[size];
                    int readCount = readIntArrayFromFile(inputFilePath, dataBuffer, size);
                    if (readCount <= 0)
                    {
                        printf("File Read Error, ERR_CODE : %d", readCount);
                        exit(1);
                    }
                    
                    bubbleSortIntArray(&dataBuffer[0], ARRAYSIZE(dataBuffer), ASC);
                    for (i = 0; i < size; i++)
                    {
                        printf("[%d] = %d\n", i, dataBuffer[i]);
                    }
                    int scan;
                    printf("Enter Element to search : ");
                    scanf("%d",&scan);
                    
                    binarySearch(&dataBuffer[0],0,1449,scan);
                    if(retn==0)
                    printf("Not Found\n");
                    else
                    {
                        printf("\nBinary Search : \n");
                        printf("\nElement = %d Found at Index = %d\n",dataBuffer[retn],retn);
                    }


                    linearSearch(&dataBuffer[0],scan);
                  

                    /* END */
                    int writeCount = writeIntArrayToFile(outputFilePath, dataBuffer, size);
                    if (writeCount <= 0)
                    {
                        printf("File Write Error, ERR_CODE : %d", writeCount);
                        exit(1);
                    }
                }
                else
                {
                    printf("Data size should be greater then 0.\n");
                    exit(1);
                }
            }
            else
            {
                printf("Input/Output or both filepath missing.\n");
                exit(1);
            }
        }
        else
        {
            printf("usage: %s -i input_filename -o output_filename -s input_data_size\n", argv[0]);
            exit(1);
        }
    }

    return 0;
}

//*******************read Array from file***************************//
int readIntArrayFromFile(const char *inputFilePath, int dataBuffer[], int dataBufferSize)
{
    FILE *fp;
    int readCount = 0;
    fp = fopen(inputFilePath, "rb");
    if (fp == NULL)
    {
        return FILE_READ_ERROR;
    }
    readCount = fread(dataBuffer, sizeof(int), dataBufferSize, fp);
    fclose(fp);
    return readCount;
}

//*******************write Array in File******************************//
int writeIntArrayToFile(const char *outputFilePath, int dataBuffer[], int dataBufferSize)
{
    FILE *fp;
    int writeCount = 0;
    fp = fopen(outputFilePath, "wb");
    if (fp == NULL)
    {
        return FILE_WRITE_ERROR;
    }
    writeCount = fwrite(dataBuffer, sizeof(int), dataBufferSize, fp);
    fclose(fp);
    return writeCount;
}

/* Define your own function(s) below*/
void bubbleSortIntArray(int *p, size_t arraySize, int sortOrder)
{
    int temp;
    size_t size = arraySize;
    int i,j;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            /* code */
            //for ascending sort
            if (sortOrder == ASC)
            {
                if (*(p+i) > *(p+j))
                {
                    //swap
                    temp = *(p+j);
                    *(p+j) = *(p+i);
                    *(p+i) = temp;
                }
            }
            //for desending sort
            else
            {
                if (*(p+j) > *(p+i))
                {
                    //swap
                    temp = *(p+i);
                    *(p+i) = *(p+j);
                    *(p+j) = temp;
                }
            }
        }
    }
}

/** ==> My Functions begin from here : */

int binarySearch(int *p,int min,int max,int srch)
{
    
int mid=(min+max)/2;

    if(min>max) return -1;
    if(*(p+mid)==srch) {  retn=mid; return 0; }
    if(min==max) return -1;

    if(srch>*(p+mid)){ 
       binarySearch(p,mid+1,max,srch);
    }
    else { 
       binarySearch(p,min,mid-1,srch);
    }
    return 0;
}

void linearSearch(int *p,int srch)
{
    for(int i=0;i<1450;++i)
    {
        if(*(p+i)==srch)
        {
           printf("\nLinear Search\n");
           printf("\nElement = %d Found at Index = %d\n",*(p+i),i);
        }

    }
}