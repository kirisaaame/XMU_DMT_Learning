package com.example.demo;

import java.util.List;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.TextArea;
import javafx.scene.text.Font;
import javafx.scene.text.FontPosture;
import javafx.scene.text.FontWeight;
import javafx.stage.Stage;

public class FontController {
    //字体
    @FXML
    private ComboBox<String> Cb1;
    //字形
    @FXML
    private ComboBox<String> Cb2;
    //大小
    @FXML
    private ComboBox<String> Cb3;
    @FXML
    private Button SureBtn;
    @FXML
    private TextArea ta;

    public Font Txtfont=Font.font(12);
    private Font font=Font.font(12);

    //字体
    String type="宋体";
    //字形
    String special="常规";
    //大小
    int size=12;

    @FXML
    void initialize() {

        List<String> getFontName = Font.getFontNames();
        Cb1.getItems().addAll(getFontName);

        Cb2.getItems().addAll("常规","粗体","斜体","粗斜体");

        for(int i=2;i<=32;i=i+2)
        {
            Cb3.getItems().add(i+"");
        }

        Cb1.setOnAction(e->{
            type = Cb1.getValue();
            setFont();
        });

        Cb2.setOnAction(e->{
            special = Cb2.getValue();
            setFont();
        });

        Cb3.setOnAction(e->{
            size = Integer.parseInt(Cb3.getValue());
            setFont();
        });
    }


    //设置字体样式
    public void setFont() {
        font = Font.font(type, size);
        if(special.equals("常规"))
            font=Font.font(type, FontWeight.NORMAL, FontPosture.REGULAR,size);//常规
        else if(special.equals("粗体"))
            font=Font.font(type, FontWeight.BOLD, FontPosture.REGULAR,size);//粗体
        else if(special.equals("斜体"))
            font=Font.font(type, FontWeight.NORMAL, FontPosture.ITALIC,size);//斜体
        else if(special.equals("粗斜体"))
            font=Font.font(type, FontWeight.BOLD, FontPosture.ITALIC,size);//粗斜体
        ta.setFont(font);
    }


    @FXML
    void onSureBtn(ActionEvent event) {
        Txtfont=font;
        Scene scene = SureBtn.getScene();
        //把选定的字体记录到用户数据中
        scene.setUserData(Txtfont);
        //点击确定后,关闭窗口
        Stage stage=(Stage)SureBtn.getScene().getWindow();
        stage.close();
    }

}

