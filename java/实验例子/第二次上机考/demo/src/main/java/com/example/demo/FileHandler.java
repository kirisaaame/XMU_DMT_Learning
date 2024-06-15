package com.example.demo;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class FileHandler {
    private static final String FILE_PATH = "students.dat";// 学生数据文件路径
    private List<People> people;

    public FileHandler() {
        people = new ArrayList<>();
        loadPeopleFromFile();
    }

    private void loadPeopleFromFile() {
        File file = new File(FILE_PATH);
        if (!file.exists()) {
            try {
                file.createNewFile();
            } catch (IOException e) {
                System.out.println("创建员工数据文件失败: " + e.getMessage());
            }
        }

        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(file))) {
            people = (List<People>) ois.readObject();
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("加载员工数据时出错: " + e.getMessage());
        }
    }// 读取文件中的学生数据

    public void savePeopleToFile() {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(FILE_PATH))) {
            oos.writeObject(people);
        } catch (IOException e) {
            System.out.println("保存员工数据时出错: " + e.getMessage());
        }
    }// 保存学生数据到文件

    public void addPeople(People people) {
        this.people.add(people);
        savePeopleToFile();
    }// 添加学生

    public void deletePeople(People people) {
        this.people.remove(people);
        savePeopleToFile();
    }// 删除学生

    public void updatePeople(People people) {
        
        savePeopleToFile();
    }// 更新学生

    public List<People> getAllPeople() {
        return people;
    }
}
