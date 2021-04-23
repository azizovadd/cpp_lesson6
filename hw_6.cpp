#include <iostream>
#include <fstream>


bool read_and_find (const char* text,const char* file)
{
    std::string text_to_find;
    std::ifstream search_file {file};
    while (search_file >> text_to_find)
    {
        if (text_to_find == text)
        {
            return true;
        }
    }
    
   return false;

}

int main()
{
    //1. Написать программу, которая создаст два текстовых файла, примерно по 50-100 символов в каждом;
    
    std::ofstream fout1 ("text1.txt");//вывод текста в файл1
    fout1<<"We chose 10 artworks that would guide the colors throughout the page";
    fout1.close();

    std::ofstream fout2 ("text2.txt");//вывод текста в файл2
    fout2<<" We really wanted the colors of 2020 to establish the identity instead of us providing them";
    fout2.close();

//2. Написать функцию, «склеивающую» эти файлы, предварительно буферизуя их содержимое в динамически выделенный сегмент памяти нужного размера.
    
    std::ifstream file1 {"text1.txt", std::ios_base::binary};
    file1.seekg(0, std::ios_base::end);
    size_t size1 = file1.tellg();
    file1.seekg(0);
    
    std::ifstream file2 {"text2.txt", std::ios_base::binary};
    file2.seekg(0, std::ios_base::end);
    size_t size2 = file2.tellg();
    file2.seekg(0);
   
    char* file_size3 = new char[size1+size2];
    file1.read(file_size3, size1);
    file2.read(file_size3 + size1, size2);

    std::ofstream file3 ("text3.txt");
    
    file3.write(file_size3, size1+size2);
    file1.close();
    file2.close();
    file3.close();
       
  //3. * Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово в указанном пользователем файле
    
    std::cout<<std::boolalpha<<read_and_find("colors","text2.txt");



    return 0;
}