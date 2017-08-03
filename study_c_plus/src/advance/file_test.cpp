/*
 * file: os = output file,  if = input file
 *   ofstream. 文件输出流。创建和对文件写操作
 *   ifstream  文件输入流。读取文件
 *   fstream   文件流。支持读写
 *
 *  void open(const char *filename, ios::openmode mode);// 配套函数close()
 *  ios::app  追加append
 *  ios::ate  文件打开后定位到文件末尾
 *  ios::in   打开文件用于读取
 *  ios::out    打开文件用于写入
 *  ios::trunc  如果文件存在。就删除已有的文件内容。即设置文件长度为0
 */

#include <fstream>
#include <iostream>
#include "../mylib/logger.h"
using namespace std;

void testFileIO(){

    char data[100];

    ofstream out;
    out.open("afile.dat");

    logM("writing to the file <<<");
    logM("Enter you name: ", false);
    cin.getline(data, 100);

    //向文件写入用户数据.
    out << data << endl;

    logM("Enter your age: ");
    cin >> data;
    cin.ignore();

    //再次向文件写入用户数据.
    out << data << endl;

    out.close();

    ifstream in;
    in.open("afile.dat");

    logM("Reading from the file >>>");
    in >> data;

    //在屏幕写入数据
    logM(data);
    //从文件读取数据 到data缓冲区
    in >> data;
    logM(data);

    in.close();
}






