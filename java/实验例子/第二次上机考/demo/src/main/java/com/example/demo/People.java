package com.example.demo;

import java.io.Serializable;

public class People implements Serializable {
    private String ID;
    private String name;
    private String Department;
    private String Level;


    public People(String studentId, String name, String Department, String Level) {
        this.ID = studentId;
        this.name = name;
        this.Department = Department;
        this.Level = Level;
    }

    public String getID() {
        return ID;
    }

    public void setID(String studentId) {
        this.ID = studentId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDepartment() {
        return Department;
    }

    public void setDepartment(String department) {
        this.Department = department;
    }

    public String getLevel() {
        return Level;
    }

    public void setLevel(String level) {
        this.Level = level;
    }
}

