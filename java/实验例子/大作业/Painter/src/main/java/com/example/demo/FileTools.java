package com.example.demo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class FileTools {

    //读文件
    public static String readFile(File file) {
        StringBuilder resultStr = new StringBuilder();//存储文件内容
        try {
            BufferedReader bReader = new BufferedReader(new FileReader(file));//读取文件
            String line = bReader.readLine();//读取文件内容
            while (line != null) {
                resultStr.append(line+"\n");//将文件内容存储到resultStr中
                line = bReader.readLine();//读取文件内容
            }
            bReader.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return resultStr.toString();
    }

    //写文件
    public static void writeFile(File file, String str) {
        try {
            BufferedWriter bWriter = new BufferedWriter(new FileWriter(file));
            bWriter.write(str);
            bWriter.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
