package com.example.demo;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class FileHandler {
    private static final String FILE_PATH = "students.dat";// 学生数据文件路径
    private List<Student> students;

    public FileHandler() {
        students = new ArrayList<>();
        loadStudentsFromFile();
    }

    private void loadStudentsFromFile() {
        File file = new File(FILE_PATH);
        if (!file.exists()) {
            try {
                file.createNewFile();
            } catch (IOException e) {
                System.out.println("创建学生数据文件失败: " + e.getMessage());
            }
        }

        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(file))) {
            students = (List<Student>) ois.readObject();
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("加载学生数据时出错: " + e.getMessage());
        }
    }

    public void saveStudentsToFile() {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(FILE_PATH))) {
            oos.writeObject(students);
        } catch (IOException e) {
            System.out.println("保存学生数据时出错: " + e.getMessage());
        }
    }

    public void addStudent(Student student) {
        students.add(student);
        saveStudentsToFile();
    }

    public void deleteStudent(Student student) {
        students.remove(student);
        saveStudentsToFile();
    }

    public void updateStudent(Student student) {
        // 可以根据需要实现更新逻辑
        saveStudentsToFile();
    }

    public List<Student> getAllStudents() {
        return students;
    }
}
