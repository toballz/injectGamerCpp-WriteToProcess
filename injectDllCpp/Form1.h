#pragma once
#include "injector.h" 
#include "otherFunctions.h" 

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
		// if user tries to close app
		void OnFormClosing(FormClosingEventArgs^ e) override {
			if (MessageBox::Show("Do you really want to close the application?", "Confirm", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No) {
				e->Cancel = true;
			}
		}
	private: System::Windows::Forms::Button^ inject;
	private: System::Windows::Forms::Label^ txtActivated;
	private: System::Windows::Forms::Label^ leaveappopen;
	private: System::Windows::Forms::Panel^ injectPanel;
	private: System::Windows::Forms::Panel^ licenceKeyPanel;
	private: System::Windows::Forms::TextBox^ licenceKeyTextInput;
	private: System::Windows::Forms::Button^ licenceKeyVerifyButton;


	private: System::Windows::Forms::Label^ label1;










	protected:

	protected:

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
			this->inject = (gcnew System::Windows::Forms::Button());
			this->txtActivated = (gcnew System::Windows::Forms::Label());
			this->leaveappopen = (gcnew System::Windows::Forms::Label());
			this->injectPanel = (gcnew System::Windows::Forms::Panel());
			this->licenceKeyPanel = (gcnew System::Windows::Forms::Panel());
			this->licenceKeyTextInput = (gcnew System::Windows::Forms::TextBox());
			this->licenceKeyVerifyButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->injectPanel->SuspendLayout();
			this->licenceKeyPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// inject
			// 
			this->inject->Cursor = System::Windows::Forms::Cursors::Hand;
			this->inject->Location = System::Drawing::Point(101, 173);
			this->inject->Name = L"inject";
			this->inject->Size = System::Drawing::Size(375, 58);
			this->inject->TabIndex = 0;
			this->inject->Text = L"Inject";
			this->inject->UseVisualStyleBackColor = true;
			this->inject->Click += gcnew System::EventHandler(this, &Form1::inject_Click);
			// 
			// txtActivated
			// 
			this->txtActivated->AutoSize = true;
			this->txtActivated->ForeColor = System::Drawing::Color::MistyRose;
			this->txtActivated->Location = System::Drawing::Point(212, 58);
			this->txtActivated->Name = L"txtActivated";
			this->txtActivated->Padding = System::Windows::Forms::Padding(15);
			this->txtActivated->Size = System::Drawing::Size(142, 46);
			this->txtActivated->TabIndex = 1;
			this->txtActivated->Text = L"Click inject to start";
			// 
			// leaveappopen
			// 
			this->leaveappopen->AutoSize = true;
			this->leaveappopen->ForeColor = System::Drawing::Color::MistyRose;
			this->leaveappopen->Location = System::Drawing::Point(172, 142);
			this->leaveappopen->Name = L"leaveappopen";
			this->leaveappopen->Size = System::Drawing::Size(0, 16);
			this->leaveappopen->TabIndex = 2;
			// 
			// injectPanel
			// 
			this->injectPanel->Controls->Add(this->licenceKeyPanel);
			this->injectPanel->Controls->Add(this->leaveappopen);
			this->injectPanel->Controls->Add(this->txtActivated);
			this->injectPanel->Controls->Add(this->inject);
			this->injectPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->injectPanel->Location = System::Drawing::Point(0, 0);
			this->injectPanel->Name = L"injectPanel";
			this->injectPanel->Size = System::Drawing::Size(572, 253);
			this->injectPanel->TabIndex = 3;
			// 
			// licenceKeyPanel
			// 
			this->licenceKeyPanel->Controls->Add(this->licenceKeyTextInput);
			this->licenceKeyPanel->Controls->Add(this->licenceKeyVerifyButton);
			this->licenceKeyPanel->Controls->Add(this->label1);
			this->licenceKeyPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->licenceKeyPanel->Location = System::Drawing::Point(0, 0);
			this->licenceKeyPanel->Name = L"licenceKeyPanel";
			this->licenceKeyPanel->Size = System::Drawing::Size(572, 253);
			this->licenceKeyPanel->TabIndex = 1;
			// 
			// licenceKeyTextInput
			// 
			this->licenceKeyTextInput->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 13.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->licenceKeyTextInput->Location = System::Drawing::Point(12, 142);
			this->licenceKeyTextInput->MaxLength = 33;
			this->licenceKeyTextInput->Multiline = true;
			this->licenceKeyTextInput->Name = L"licenceKeyTextInput";
			this->licenceKeyTextInput->Size = System::Drawing::Size(548, 41);
			this->licenceKeyTextInput->TabIndex = 7;
			// 
			// licenceKeyVerifyButton
			// 
			this->licenceKeyVerifyButton->BackColor = System::Drawing::Color::LawnGreen;
			this->licenceKeyVerifyButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->licenceKeyVerifyButton->Location = System::Drawing::Point(51, 189);
			this->licenceKeyVerifyButton->Name = L"licenceKeyVerifyButton";
			this->licenceKeyVerifyButton->Size = System::Drawing::Size(463, 57);
			this->licenceKeyVerifyButton->TabIndex = 6;
			this->licenceKeyVerifyButton->Text = L"Verify licence Key";
			this->licenceKeyVerifyButton->UseVisualStyleBackColor = false;
			this->licenceKeyVerifyButton->Click += gcnew System::EventHandler(this, &Form1::licenceKeyVerifyButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::MistyRose;
			this->label1->Location = System::Drawing::Point(215, 86);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(154, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Type/Paste Licence Key";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(572, 253);
			this->Controls->Add(this->injectPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(590, 300);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(590, 300);
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->injectPanel->ResumeLayout(false);
			this->injectPanel->PerformLayout();
			this->licenceKeyPanel->ResumeLayout(false);
			this->licenceKeyPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		//*********** 
		private:System::String^ err_list(int errCodeER) {
			switch (errCodeER) {
				case -112:
					return "The game is not running yet. Please start the game and click the inject button again!" ;
					break;
				case -115:
					return "PID not found :( exiting...\n";
					break;
				default:
					return "";
			}
		}
		//***********

		private: System::Void inject_Click(System::Object^ sender, System::EventArgs^ e){
 				int errCode = injectDllActivate();
				if (errCode < 0) {
					MessageBox::Show(err_list(errCode),
						"Check",
						MessageBoxButtons::OK,
						MessageBoxIcon::Information);
				}else {
					txtActivated->Text = "Hack activated.";
					txtActivated->BackColor = BackColor.ForestGreen;
					inject->Enabled = false;
					leaveappopen->Text = "Leave this box open ;)";

					listenforKey();
				}
			 
		}
	private: System::Void licenceKeyVerifyButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (licenceKeyTextInput->Text->Length > 0) {
			licenceKeyPanel->Visible = false;
			injectPanel->Visible = true;
			LocalStorage::store("Licence", licenceKeyTextInput->Text);
		}
		 
	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		if (LocalStorage::get("Licence").size() > 0) {

			licenceKeyPanel->Visible = false;
			injectPanel->Visible = true;
		}

	} 
};
}
