#pragma once
#include"file_management.h"
#include "ImpFuncs.h"

namespace DsFinalP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}


	private: int glblvar = 0;
	private: map_file* m = new map_file();

	private: System::Windows::Forms::ComboBox^ comboBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(33, 269);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(201, 24);
			this->comboBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::DarkOrange;
			this->label1->Location = System::Drawing::Point(25, 241);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(148, 29);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Your Location";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::DarkOrange;
			this->label2->Location = System::Drawing::Point(28, 322);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(171, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Your Destination";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(33, 350);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(201, 24);
			this->comboBox2->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Orange;
			this->button1->Font = (gcnew System::Drawing::Font(L"Wide Latin", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(30, 78);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(248, 72);
			this->button1->TabIndex = 4;
			this->button1->Text = L"InterCity";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::DarkOrange;
			this->label3->Location = System::Drawing::Point(170, 23);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(289, 25);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Choose Your Mode of Travel";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Salmon;
			this->button2->Font = (gcnew System::Drawing::Font(L"Wide Latin", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(317, 78);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(248, 72);
			this->button2->TabIndex = 6;
			this->button2->Text = L"IntraCity";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm2::button2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(635, 66);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 17);
			this->label4->TabIndex = 7;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Gold;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(6, 179);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(150, 25);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Shortest Path:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Gold;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(175, 179);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(24, 25);
			this->label6->TabIndex = 9;
			this->label6->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Gold;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(285, 179);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(40, 25);
			this->label7->TabIndex = 10;
			this->label7->Text = L"km";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::SystemColors::Highlight;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(6, 213);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(67, 25);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Time:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::SystemColors::Highlight;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(175, 213);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(24, 25);
			this->label9->TabIndex = 12;
			this->label9->Text = L"0";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::SystemColors::Highlight;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(285, 213);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(58, 25);
			this->label10->TabIndex = 13;
			this->label10->Text = L"Mins";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::LimeGreen;
			this->groupBox1->Controls->Add(this->label13);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Wide Latin", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(260, 171);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(368, 330);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Journey Info";
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::LightGreen;
			this->groupBox2->Controls->Add(this->radioButton2);
			this->groupBox2->Controls->Add(this->radioButton1);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(11, 34);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(306, 142);
			this->groupBox2->TabIndex = 16;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Path by:";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton2->Location = System::Drawing::Point(10, 75);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(115, 32);
			this->radioButton2->TabIndex = 15;
			this->radioButton2->Text = L"Distance";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton1->Location = System::Drawing::Point(10, 37);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(80, 32);
			this->radioButton1->TabIndex = 14;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Time";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::Highlight;
			this->button3->Font = (gcnew System::Drawing::Font(L"Lucida Calligraphy", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->button3->Location = System::Drawing::Point(33, 419);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(183, 72);
			this->button3->TabIndex = 15;
			this->button3->Text = L"Travel";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm2::button3_Click);
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(30, 205);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(201, 24);
			this->comboBox3->TabIndex = 16;
			this->comboBox3->Visible = false;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm2::comboBox3_SelectedIndexChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Calibri", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::DarkOrange;
			this->label11->Location = System::Drawing::Point(28, 171);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(115, 29);
			this->label11->TabIndex = 17;
			this->label11->Text = L"Select City";
			this->label11->Visible = false;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::Gold;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(6, 248);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(75, 25);
			this->label12->TabIndex = 17;
			this->label12->Text = L"Route:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::SystemColors::Highlight;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(6, 282);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(60, 25);
			this->label13->TabIndex = 18;
			this->label13->Text = L"none";
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(650, 529);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		label11->Visible = false;
		comboBox3->Visible = false;
		glblvar = 0;

		comboBox1->Items->Clear();
		comboBox2->Items->Clear();

		std::string c;
		std::vector<city> cty = m->get_all_cities();
		cli::array < System::Object^>^ xyz = gcnew cli::array<System::Object^>(cty.size());
		int i = 0;

		for (auto itratr : cty) {
			std::string val = itratr.name + "~" + std::to_string(itratr.post_code);
			auto ab = gcnew String(val.c_str());
			xyz[i] = ab;
			i++;
		}
		comboBox1->Items->AddRange(xyz);
		comboBox2->Items->AddRange(xyz);

	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	label11->Visible = true;
	comboBox3->Visible = true;
	glblvar = 1;




}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	
	std::string cbo = toStandardString((comboBox1->Items[comboBox1->SelectedIndex])->ToString());
	std::vector<std::string> v = explode(cbo, '~');

	std::string cbo1 = toStandardString((comboBox2->Items[comboBox2->SelectedIndex])->ToString());
	std::vector<std::string> v1 = explode(cbo1, '~');

	

	do_by db;
	if (radioButton1->Checked) {
		db = do_by::time;
	}
	else {
		db = do_by::distance;
	}
	graph g;
	if (glblvar == 0) {
		
	g = m->make_graph();
	
	}
	else {
		std::string cbo2;
		std::vector<std::string> v2;
		cbo2 = toStandardString((comboBox3->Items[comboBox3->SelectedIndex])->ToString());
		v2 = explode(cbo2, '~');
		g = m->make_graph(v2[0]);
	}
	
	auto n = g.dijkstra(std::stoi(v[1]),std::stoi( v1[1]),db);
	
	if (db == do_by::distance) {
		label6->Text = n.shortest_path.ToString();
		label9->Text = n.other_path.ToString();
	}
	else {
		label9->Text = n.shortest_path.ToString();
		label6->Text = n.other_path.ToString();
	}
	std::string route;
	for (int i : n.path) {
		city c = g.search_locations(i);
		route += c.name + " > ";
	}
	label13->Text = gcnew String(route.c_str());

}
private: System::Void MyForm2_Load(System::Object^ sender, System::EventArgs^ e) {
	std::string c;
	std::vector<city> cty = m->get_all_cities();
	cli::array < System::Object^>^ xyz = gcnew cli::array<System::Object^>(cty.size());
	int i = 0;

	for (auto itratr : cty) {
		std::string val = itratr.name + "~" + std::to_string(itratr.post_code);
		auto ab = gcnew String(val.c_str());
		xyz[i] = ab;
		i++;
	}
	comboBox1->Items->AddRange(xyz);
	comboBox2->Items->AddRange(xyz);
	comboBox3->Items->AddRange(xyz);
}
private: System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	
	std::string cbo = toStandardString((comboBox3->Items[comboBox3->SelectedIndex])->ToString());
	std::vector<std::string> v = explode(cbo, '~');
	
	comboBox1->Items->Clear();
	comboBox2->Items->Clear();
	
	std::string c;
	std::vector<city> cty = m->get_all_cities(v[0]);
	cli::array < System::Object^>^ xyz = gcnew cli::array<System::Object^>(cty.size());
	int i = 0;

	for (auto itratr : cty) {
		std::string val = itratr.name + "~" + std::to_string(itratr.post_code);
		auto ab = gcnew String(val.c_str());
		xyz[i] = ab;
		i++;
	}
	comboBox1->Items->AddRange(xyz);
	comboBox2->Items->AddRange(xyz);

}
};
}
