package com.example.demo;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

public class FindReplaceController {

    @FXML
    private TextField findTextField;

    @FXML
    private TextField replaceTextField;

    private EditorController editorController;

    public void setEditorController(EditorController editorController) {
        this.editorController = editorController;
    }

    @FXML
    void findNextButtonClicked(ActionEvent event) {
        String textToFind = findTextField.getText();
        if (!textToFind.isEmpty()) {
            editorController.findText(textToFind);
        } else {
            new Alert(Alert.AlertType.WARNING, "请输入查找内容").show();
        }
    }

    @FXML
    void findPreviousButtonClicked(ActionEvent event) {
        String textToFind = findTextField.getText();
        if (!textToFind.isEmpty()) {
            editorController.findPreviousText(textToFind);
        } else {
            new Alert(Alert.AlertType.WARNING, "请输入查找内容").show();
        }
    }

    @FXML
    void replaceButtonClicked(ActionEvent event) {
        String textToFind = findTextField.getText();
        String replacementText = replaceTextField.getText();
        if (!textToFind.isEmpty()) {
            editorController.replaceText(textToFind, replacementText);
        } else {
            new Alert(Alert.AlertType.WARNING, "请输入查找内容").show();
        }
    }

    @FXML
    void replaceAllButton(ActionEvent event) {
        String textToFind = findTextField.getText();
        String replacementText = replaceTextField.getText();
        if (!textToFind.isEmpty()) {
            editorController.replaceAllText(textToFind, replacementText);
        } else {
            new Alert(Alert.AlertType.WARNING, "请输入查找内容").show();
        }
    }

}
