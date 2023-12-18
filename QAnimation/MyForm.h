#pragma once
#include"../Queue/TQueue.h"
#include <string>
#include<msclr\marshal_cppstd.h>
//#include <>
namespace circlebuffer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		double p, q;
		int pushcount = 0;
		int popcount = 0;
		TQueue<int>* Circlequeue;
		int mid_x = 450;
		int mid_y = 80;
		int weight = 150;
		int height = 150;
		int f = 0;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label11;
		   Random^ rnd = (gcnew Random());
		void Draw()
		{
			int start = 360 * Circlequeue->GetHeadIndex() / Circlequeue->GetMaxSize();
			int finish = 360 * Circlequeue->NumberOfElements() / Circlequeue->GetMaxSize();
			Pen^ My_draw_pen = gcnew Pen(Color::Black);
			My_draw_pen->Width = 10.0F;
			Graphics^ graf = CreateGraphics();
			graf->DrawArc(My_draw_pen, mid_x, mid_y, weight, height, start, finish);
		}
		void Clear()
		{
			int start = 360 * Circlequeue->GetHeadIndex() / Circlequeue->GetMaxSize();
			int finish = 360 * Circlequeue->NumberOfElements() / Circlequeue->GetMaxSize();
			Pen^ My_pen = gcnew Pen(Color::White);
			My_pen->Width = 10.0F;
			Graphics^ graf = CreateGraphics();
			graf->DrawArc(My_pen, mid_x, mid_y, weight, height, start, finish);
		}

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(32, 36);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(164, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Максимальная длина очереди:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(32, 62);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(136, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Исходная длина очереди:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(32, 92);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(143, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Веротятность добавления:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(32, 121);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(139, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Вероятность исключения:";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(32, 151);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(120, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Добавлено в очередь:";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(32, 182);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(124, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Извлечено из очереди:";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(32, 211);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(180, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Количество элементов в очереди:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Aquamarine;
			this->label8->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label8->Location = System::Drawing::Point(225, 151);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(55, 13);
			this->label8->TabIndex = 7;
			this->label8->Text = L"                ";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Aquamarine;
			this->label9->Location = System::Drawing::Point(225, 182);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(55, 13);
			this->label9->TabIndex = 8;
			this->label9->Text = L"                ";
			this->label9->Click += gcnew System::EventHandler(this, &MyForm::label9_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Aquamarine;
			this->label10->Location = System::Drawing::Point(225, 211);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(55, 13);
			this->label10->TabIndex = 9;
			this->label10->Text = L"                ";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Aquamarine;
			this->textBox1->Location = System::Drawing::Point(224, 36);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(56, 20);
			this->textBox1->TabIndex = 10;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::Aquamarine;
			this->textBox2->Location = System::Drawing::Point(224, 62);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(56, 20);
			this->textBox2->TabIndex = 11;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::Aquamarine;
			this->textBox3->Location = System::Drawing::Point(224, 92);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(56, 20);
			this->textBox3->TabIndex = 12;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::Aquamarine;
			this->textBox4->ForeColor = System::Drawing::Color::Yellow;
			this->textBox4->Location = System::Drawing::Point(224, 121);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(56, 20);
			this->textBox4->TabIndex = 13;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Yellow;
			this->button1->Location = System::Drawing::Point(309, 243);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(73, 41);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Старт";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Yellow;
			this->button2->Location = System::Drawing::Point(386, 243);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(64, 41);
			this->button2->TabIndex = 16;
			this->button2->Text = L"Пауза";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Yellow;
			this->button3->Location = System::Drawing::Point(454, 243);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(81, 41);
			this->button3->TabIndex = 17;
			this->button3->Text = L"Финиш";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(432, 151);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(0, 13);
			this->label12->TabIndex = 18;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::AliceBlue;
			this->label11->Location = System::Drawing::Point(169, 9);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(213, 13);
			this->label11->TabIndex = 19;
			this->label11->Text = L"Состояние буфера циклической очереди";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(618, 447);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	label12->Text = " ";
	p = Convert::ToDouble(textBox3->Text);
	q = Convert::ToDouble(textBox4->Text);
	
	if (f == 0)
	{
		int Maxsize = Convert::ToInt32(textBox1->Text);
		int size = Convert::ToInt32(textBox2->Text);
		Circlequeue = new TQueue<int>(Maxsize);
		f = 1;
		for (int i = 0; i < size; i++)
		{
			Circlequeue->Push(1);

		}
	}
	timer1->Enabled = true;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	timer1->Enabled = false;
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	timer1->Enabled = false;
	Clear();
	delete Circlequeue;
	f = 0;
	pushcount = 0;
	popcount = 0;
	label8->Text = Convert::ToString(0);
	label9->Text = Convert::ToString(0);
	label10->Text = Convert::ToString(0);
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	try 
	{
		if (!Circlequeue->empty())
			Clear();
		if (rnd->NextDouble() < p)
		{
			Circlequeue->Push(1);
			pushcount++;
		}

	    if (rnd->NextDouble() < q)
	    {
				Circlequeue->Pop();
				popcount++;
	    }
		
		Draw();
		label8->Text = Convert::ToString(pushcount);
		label9->Text = Convert::ToString(popcount);
		label10->Text = Convert::ToString(Circlequeue->NumberOfElements());
		
	}
	catch (const char* ex)
	{
		label12->Text = "Error in TQueue! Tqueue are Full or Empty.";
		timer1->Enabled = false;
		Clear();
		delete Circlequeue;
		f = 0;
		pushcount = 0;
		popcount = 0;
		label8->Text = Convert::ToString(0);
		label9->Text = Convert::ToString(0);
		label10->Text = Convert::ToString(0);

	}


}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
