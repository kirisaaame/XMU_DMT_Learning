package com.example.demo;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.ColorPicker;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;

public class PainterController {

    @FXML private AnchorPane drawingAreaAnchorPane;
    private Color chosenColor = Color.BLACK;

    @FXML
    private void handleRectangleButton(ActionEvent event) {
        Rectangle rectangle = new Rectangle(100, 100, chosenColor);
        rectangle.setX(100);
        rectangle.setY(100);
        drawingAreaAnchorPane.getChildren().add(rectangle);
    }

    @FXML
    private void handleCircleButton(ActionEvent event) {
        Circle circle = new Circle(100, chosenColor);
        circle.setCenterX(100);
        circle.setCenterY(500);
        drawingAreaAnchorPane.getChildren().add(circle);
    }

    @FXML
    private void handleLineButton(ActionEvent event) {
        Line line = new Line(50, 50, 200, 200);
        line.setStroke(chosenColor);
        drawingAreaAnchorPane.getChildren().add(line);
    }

    @FXML
    private void handleColorPicker(ActionEvent event) {
        ColorPicker colorPicker = new ColorPicker();
        colorPicker.setOnAction(e -> {
            chosenColor = colorPicker.getValue();
        });
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Color Picker");
        alert.setHeaderText(null);
        alert.setContentText("Choose a color:");
        alert.getDialogPane().setContent(colorPicker);
        alert.showAndWait();
    }
}
