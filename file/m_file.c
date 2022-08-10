//
// Created by hoang on 8/8/2022.
//

#include <stdio.h>
#include "m_file.h"
char debugView;
void file_main()
{

    char filePath[] = "C:\\Users\\hoang\\CLionProjects\\C17Test\\file\\textFile.txt";
    FILE * fp = fopen(filePath, "r") ;
    (void)fp;

}