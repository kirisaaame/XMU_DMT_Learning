package com.example.demo;

import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;

import java.util.List;
import java.util.stream.Collectors;

public class MainLayoutController {

    private FileHandler fileHandler;
    private List<Student> students;
    private int currentIndex;

    @FXML
    private TextField studentIdField;
    @FXML
    private TextField nameField;
    @FXML
    private TextField phoneField;
    @FXML
    private TextField emailField;
    @FXML
    private TextField queryNameField;

    public MainLayoutController() {
        fileHandler = new FileHandler();
        students = fileHandler.getAllStudents();
        currentIndex = 0;
    }

    @FXML
    public void initialize() {
        if (!students.isEmpty()) {
            showStudentInfo(currentIndex);
        }
    }

    @FXML
    private void handleAdd() {
        String studentId = studentIdField.getText();
        String name = nameField.getText();
        String phone = phoneField.getText();
        String email = emailField.getText();

        if (studentId.isEmpty() || name.isEmpty() || phone.isEmpty() || email.isEmpty()) {
            showAlert("请填写完整的学生信息");
            return;
        }

        Student newStudent = new Student(studentId, name, phone, email);
        fileHandler.addStudent(newStudent);
        students = fileHandler.getAllStudents();
        showAlert("新增学生成功");
    }

    @FXML
    private void handleDelete() {
        if (students.isEmpty()) {
            showAlert("没有学生数据可以删除");
            return;
        }

        Student studentToDelete = students.get(currentIndex);
        fileHandler.deleteStudent(studentToDelete);
        students = fileHandler.getAllStudents();
        showAlert("删除学生成功");
        currentIndex = 0; // 重置索引
        showStudentInfo(currentIndex);
    }

    @FXML
    private void handleUpdate() {
        if (students.isEmpty()) {
            showAlert("没有学生数据可以修改");
            return;
        }

        Student studentToUpdate = students.get(currentIndex);
        studentToUpdate.setStudentId(studentIdField.getText());
        studentToUpdate.setName(nameField.getText());
        studentToUpdate.setPhone(phoneField.getText());
        studentToUpdate.setEmail(emailField.getText());

        fileHandler.updateStudent(studentToUpdate);
        students = fileHandler.getAllStudents();
        showAlert("修改学生成功");
    }

    @FXML
    private void handleQuery() {
        String queryName = queryNameField.getText().trim();
        if (queryName.isEmpty()) {
            showAlert("请输入查询姓名");
            return;
        }

        List<Student> result = students.stream()
                .filter(student -> student.getName().equalsIgnoreCase(queryName))
                .collect(Collectors.toList());

        if (result.isEmpty()) {
            showAlert("未找到匹配的学生信息");
        } else {
            students = result;
            currentIndex = 0;
            showStudentInfo(currentIndex);
        }
    }

    @FXML
    private void handleDisplay() {
        students = fileHandler.getAllStudents();
        currentIndex = 0;
        showStudentInfo(currentIndex);
    }

    @FXML
    private void handlePrevious() {
        if (currentIndex > 0) {
            currentIndex--;
            showStudentInfo(currentIndex);
        } else {
            showAlert("已经是第一条学生信息");
        }
    }

    @FXML
    private void handleNext() {
        if (currentIndex < students.size() - 1) {
            currentIndex++;
            showStudentInfo(currentIndex);
        } else {
            showAlert("已经是最后一条学生信息");
        }
    }

    private void showStudentInfo(int index) {
        Student student = students.get(index);
        studentIdField.setText(student.getStudentId());
        nameField.setText(student.getName());
        phoneField.setText(student.getPhone());
        emailField.setText(student.getEmail());
    }

    private void showAlert(String message) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("提示");
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
}


