import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Alert;
import javafx.scene.control.TextInputDialog;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

import java.util.Optional;
import java.util.Random;

public class DrawingApplication extends Application {

    private static final int WIDTH = 800;
    private static final int HEIGHT = 600;
    private static final int MAX_SHAPES = 20;

    private Canvas canvas;
    private GraphicsContext gc;
    private int shapeCount;

    @Override
    public void start(Stage primaryStage) {
        canvas = new Canvas(WIDTH, HEIGHT);
        gc = canvas.getGraphicsContext2D();
        shapeCount = 0;

        StackPane root = new StackPane(canvas);
        primaryStage.setScene(new Scene(root));
        primaryStage.setTitle("绘图应用");
        primaryStage.show();

        drawRandomShapes();
    }

    private void drawRandomShapes() {
        Random random = new Random();
        while (shapeCount < MAX_SHAPES) {
            int shapeType = random.nextInt(3);
            switch (shapeType) {
                case 0:
                    drawLine();
                    break;
                case 1:
                    drawRectangle();
                    break;
                case 2:
                    drawEllipse();
                    break;
            }
            shapeCount++;
        }
    }

    private void drawLine() {
        TextInputDialog dialog = new TextInputDialog();
        dialog.setTitle("绘制直线");
        dialog.setHeaderText(null);
        dialog.setContentText("请输入起点X坐标、起点Y坐标、终点X坐标、终点Y坐标（0-800）：");
        Optional<String> result = dialog.showAndWait();
        result.ifPresent(s -> {
            String[] params = s.split(" ");
            if (params.length != 4) {
                showInvalidInputAlert();
                return;
            }
            try {
                double startX = Double.parseDouble(params[0]);
                double startY = Double.parseDouble(params[1]);
                double endX = Double.parseDouble(params[2]);
                double endY = Double.parseDouble(params[3]);
                if (isValidCoordinate(startX) && isValidCoordinate(startY) && isValidCoordinate(endX) && isValidCoordinate(endY)) {
                    gc.setStroke(Color.BLACK);
                    gc.strokeLine(startX, startY, endX, endY);
                } else {
                    showInvalidInputAlert();
                }
            } catch (NumberFormatException e) {
                showInvalidInputAlert();
            }
        });
    }

    private void drawRectangle() {
        TextInputDialog dialog = new TextInputDialog();
        dialog.setTitle("绘制矩形");
        dialog.setHeaderText(null);
        dialog.setContentText("请输入左上角X坐标、左上角Y坐标、宽度、高度（0-800）：");
        Optional<String> result = dialog.showAndWait();
        result.ifPresent(s -> {
            String[] params = s.split(" ");
            if (params.length != 4) {
                showInvalidInputAlert();
                return;
            }
            try {
                double x = Double.parseDouble(params[0]);
                double y = Double.parseDouble(params[1]);
                double width = Double.parseDouble(params[2]);
                double height = Double.parseDouble(params[3]);
                if (isValidCoordinate(x) && isValidCoordinate(y) && isValidSize(width) && isValidSize(height)) {
                    gc.setStroke(Color.BLACK);
                    gc.strokeRect(x, y, width, height);
                } else {
                    showInvalidInputAlert();
                }
            } catch (NumberFormatException e) {
                showInvalidInputAlert();
            }
        });
    }

    private void drawEllipse() {
        TextInputDialog dialog = new TextInputDialog();
        dialog.setTitle("绘制椭圆");
        dialog.setHeaderText(null);
        dialog.setContentText("请输入中心点X坐标、中心点Y坐标、X半径、Y半径（0-800）：");
        Optional<String> result = dialog.showAndWait();
        result.ifPresent(s -> {
            String[] params = s.split(" ");
            if (params.length != 4) {
                showInvalidInputAlert();
                return;
            }
            try {
                double centerX = Double.parseDouble(params[0]);
                double centerY = Double.parseDouble(params[1]);
                double radiusX = Double.parseDouble(params[2]);
                double radiusY = Double.parseDouble(params[3]);
                if (isValidCoordinate(centerX) && isValidCoordinate(centerY) && isValidSize(radiusX) && isValidSize(radiusY)) {
                    gc.setStroke(Color.BLACK);
                    gc.strokeOval(centerX - radiusX, centerY - radiusY, 2 * radiusX, 2 * radiusY);
                } else {
                    showInvalidInputAlert();
                }
            } catch (NumberFormatException e) {
                showInvalidInputAlert();
            }
        });
    }

    private boolean isValidCoordinate(double coordinate) {
        return coordinate >= 0 && coordinate <= WIDTH;
    }

    private boolean isValidSize(double size) {
        return size > 0 && size <= WIDTH;
    }

    private void showInvalidInputAlert() {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle("无效输入");
        alert.setHeaderText(null);
        alert.setContentText("输入无效！请输入范围内的有效数字。");
        alert.showAndWait();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
