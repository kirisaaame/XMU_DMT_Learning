package com.example.demo;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;

import java.io.*;
import java.util.List;

public class MainController {

    private FileHandler fileHandler;
    private List<People> peopleList;
    private int currentIndex;

    @FXML
    private TextField ID;
    @FXML
    private TextField Name;
    @FXML
    private TextField Department;
    @FXML
    private TextField Level;
    @FXML
    private ListView<String> Show;

    public MainController() {
        fileHandler = new FileHandler();
        peopleList = fileHandler.getAllPeople();
        currentIndex = 0;
    }

    @FXML
    public void initialize() {
        if (!peopleList.isEmpty()) {
            showPeopleInfo(currentIndex);
        }
        for (People person : peopleList) {
            Show.getItems().add(person.getID());// 将员工ID添加到ListView中
        }
    }

    @FXML
    private void handleAdd(ActionEvent event) {
        String ID = this.ID.getText();
        String Name = this.Name.getText();
        String Department = this.Department.getText();
        String Level = this.Level.getText();

        if (ID.isEmpty() || Name.isEmpty() || Department.isEmpty() || Level.isEmpty()) {
            showAlert("请填写完整的员工信息");
            return;
        }

        People newPeople = new People(ID, Name, Department, Level);
        fileHandler.addPeople(newPeople);
        peopleList = fileHandler.getAllPeople();
        Show.getItems().add(ID);
        showAlert("新增员工成功");
    }

    @FXML
    private void handleDelete(ActionEvent event) {
        if (peopleList.isEmpty()) {
            showAlert("没有员工数据可以删除");
            return;
        }

        People personToDelete = peopleList.get(currentIndex);
        fileHandler.deletePeople(personToDelete);
        peopleList = fileHandler.getAllPeople();
        Show.getItems().remove(currentIndex);
        showAlert("删除员工成功");
        currentIndex = 0;
        if (!peopleList.isEmpty()) {
            showPeopleInfo(currentIndex);
        } else {
            clearFields();
        }
    }

    @FXML
    private void handleSave(ActionEvent event) {
        if (peopleList.isEmpty()) {
            showAlert("没有员工数据可以保存");
            return;
        }

        People personToUpdate = peopleList.get(currentIndex);
        personToUpdate.setID(ID.getText());
        personToUpdate.setName(Name.getText());
        personToUpdate.setDepartment(Department.getText());
        personToUpdate.setLevel(Level.getText());

        fileHandler.updatePeople(personToUpdate);
        peopleList = fileHandler.getAllPeople();
        showAlert("保存员工成功");
    }

    @FXML
    private void handleSaveAs(ActionEvent event) {
        try {
            File writeFile = new File("src/main/resources/com/example/demo/employeesData.txt");
            if (!writeFile.exists()) {
                writeFile.createNewFile();
            }

            FileWriter writer = new FileWriter(writeFile);
            BufferedWriter out = new BufferedWriter(writer);

            for (People person : peopleList) {
                out.write(person.getID() + "," + person.getName() + "," + person.getDepartment() + "," + person.getLevel());
                out.newLine();
            }
            out.flush();
            out.close();
            showAlert("员工数据已保存到文件");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @FXML
    private void handleListViewClick(MouseEvent event) {
        String selectedID = Show.getSelectionModel().getSelectedItem();
        if (selectedID != null) {
            for (int i = 0; i < peopleList.size(); i++) {
                if (peopleList.get(i).getID().equals(selectedID)) {
                    currentIndex = i;
                    showPeopleInfo(currentIndex);
                    break;
                }
            }
        }
    }

    private void showPeopleInfo(int index) {
        People person = peopleList.get(index);
        ID.setText(person.getID());
        Name.setText(person.getName());
        Department.setText(person.getDepartment());
        Level.setText(person.getLevel());
    }

    private void clearFields() {
        ID.clear();
        Name.clear();
        Department.clear();
        Level.clear();
    }

    private void showAlert(String message) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("提示");
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
}



