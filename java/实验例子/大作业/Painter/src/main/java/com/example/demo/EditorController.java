package com.example.demo;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.BorderPane;
import javafx.stage.FileChooser;
import javafx.stage.Modality;
import javafx.stage.Stage;

import java.io.File;
import java.io.IOException;

public class EditorController {

    //定义各组件
    @FXML
    private MenuItem SaveMenu;
    @FXML
    private MenuItem FindMenu;

    @FXML
    private TextArea ta;
    @FXML
    private Label label;
    @FXML
    private MenuItem Redo;
    @FXML
    private MenuItem Undo;
    @FXML
    private CheckMenuItem WrapMenu;

    private File result;//文件路径
    private int startIndex = 0;//查找的起始位置

    public void initialize() {
        //查找、撤销、重做菜单默认不可用
        FindMenu.setDisable(true);
        Redo.setDisable(true);
        Undo.setDisable(true);

        ta.textProperty().addListener((observable, oldValue, newValue) -> {
            FindMenu.setDisable(ta.getLength() == 0);
            Redo.setDisable(false);
            Undo.setDisable(false);
        });//监听文本内容变化，设置查找、撤销、重做菜单是否可用

        ta.caretPositionProperty().addListener((observable, oldValue, newValue) -> updateStatusBar());//监听光标位置变化
    }

    @FXML
    void onNewMenu(ActionEvent event) {
        saveAdvance();
        ta.clear();
        result = null;
    }

    @FXML
    void onOpenMenu(ActionEvent event) {
        saveAdvance();
        FileChooser fileChooser = new FileChooser();
        FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter("TXT files (*.txt)", "*.txt");
        fileChooser.getExtensionFilters().add(extFilter);
        result = fileChooser.showOpenDialog(null);
        if (result != null) {
            ta.setText(FileTools.readFile(result));
        }
    }

    @FXML
    void onSaveMenu(ActionEvent event) throws IOException {
        if (result != null) {
            FileTools.writeFile(result, ta.getText());
        } else {
            FileChooser fileChooser = new FileChooser();
            FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter("TXT files (*.txt)", "*.txt");
            fileChooser.getExtensionFilters().add(extFilter);
            result = fileChooser.showSaveDialog(null);
            if (result != null) {
                FileTools.writeFile(result, ta.getText());
            }
        }
    }

    @FXML
    void handleSaveAs(ActionEvent event) throws IOException {
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("另存为");
        FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter("TXT files (*.txt)", "*.txt");
        fileChooser.getExtensionFilters().add(extFilter);
        File selectedFile = fileChooser.showSaveDialog(null);
        if (selectedFile != null) {
            FileTools.writeFile(selectedFile, ta.getText());
        }
    }

    @FXML
    void onUndoMenu(ActionEvent event) {
        ta.undo();
        Undo.setDisable(true);
    }

    @FXML
    void onRedoMenu(ActionEvent event) {
        ta.redo();
        Redo.setDisable(true);
    }

    @FXML
    void onFindMenu(ActionEvent event) {
        showFindReplaceDialog();
    }


    @FXML
    void onWrapMenu(ActionEvent event) {
        ta.setWrapText(WrapMenu.isSelected());
    }//设置自动换行

    @FXML
    void onTypefaceMenu(ActionEvent event) throws IOException {
        Stage stage = new Stage();
        FXMLLoader loader = new FXMLLoader(getClass().getResource("Font.fxml"));
        AnchorPane root = loader.load();
        Scene scene = new Scene(root);
        stage.setScene(scene);
        stage.showAndWait();
        if (scene.getUserData() != null) {
            ta.setFont((javafx.scene.text.Font) scene.getUserData());
        }
    }

    @FXML
    void updateStatusBar() {
        int lineNumber = ta.getText().substring(0, ta.getCaretPosition()).split("\n", -1).length;//获取行数
        int columnNumber = ta.getCaretPosition() - ta.getText().lastIndexOf('\n', ta.getCaretPosition() - 1);//获取列数
        String encoding = "UTF-8"; // 实际情况中根据需要获取文件编码
        label.setText("行: " + lineNumber + " 列: " + columnNumber + " 文件编码: " + encoding);
    }

    void findText(String text) {
        if (!text.isEmpty()) {
            int pos = ta.getText().indexOf(text, startIndex);//从startIndex开始查找
            if (pos != -1) {
                ta.selectRange(pos, pos + text.length());
                startIndex = pos + text.length();
            } else {
                new Alert(Alert.AlertType.INFORMATION, "未找到文本").show();
            }
        }
    }

    void findPreviousText(String text) {
        if (!text.isEmpty()) {
            int pos = ta.getText().lastIndexOf(text, startIndex);
            if (pos != -1) {
                ta.selectRange(pos-text.length(), pos);
                startIndex = pos-text.length();
            } else {
                new Alert(Alert.AlertType.INFORMATION, "未找到文本").show();
            }
        }
    }

    void replaceText(String findText, String replaceText) {
        if (!findText.isEmpty()) {
            int start = ta.getSelection().getStart();
            int end = ta.getSelection().getEnd();
            ta.replaceText(start, end, replaceText);
        }
    }

    void replaceAllText(String findText, String replaceText) {
        if (!findText.isEmpty()) {
            ta.setText(ta.getText().replaceAll(findText, replaceText));
        }
    }

    private void saveAdvance() {
        if (result != null && ta.getLength() > 0) {
            FileTools.writeFile(result, ta.getText());//不为空则保存到result文件
        } else if (result == null && ta.getLength() > 0) {
            FileChooser fileChooser = new FileChooser();
            FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter("TXT files (*.txt)", "*.txt");//创建文件过滤器，只显示txt文件
            fileChooser.getExtensionFilters().add(extFilter);//使用文件过滤器
            fileChooser.setTitle("保存当前内容");
            result = fileChooser.showSaveDialog(null);
            if (result != null) {
                FileTools.writeFile(result, ta.getText());
            }
        }
    }

    private void showFindReplaceDialog() {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("FindReplace.fxml"));
            Parent root = loader.load();

            FindReplaceController controller = loader.getController();
            controller.setEditorController(this); // Pass the reference of EditorController

            Stage stage = new Stage();
            stage.initModality(Modality.WINDOW_MODAL);
            stage.initOwner(ta.getScene().getWindow());
            stage.setTitle("查找和替换");
            stage.setScene(new Scene(root));
            stage.show();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
