package com.example.demo;

import com.example.demo.EditorController;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;

public class Editor extends Application {

    @Override
    public void start(Stage primaryStage) {
        try {
            // Load FXML file and set it as the root for the scene
            FXMLLoader loader = new FXMLLoader(getClass().getResource("Editor.fxml"));
            BorderPane root = loader.load();
            Scene scene = new Scene(root, 800, 600);

            // Set the stage properties
            primaryStage.setTitle("文本编辑器");
            primaryStage.setScene(scene);
            primaryStage.show();


        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        launch(args);
    }
}
