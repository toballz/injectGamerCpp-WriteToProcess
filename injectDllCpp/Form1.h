#pragma once
#include "injector.h" 

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
			this->SuspendLayout();
			// 
			// inject
			// 
			this->inject->Cursor = System::Windows::Forms::Cursors::Hand;
			this->inject->Location = System::Drawing::Point(83, 153);
			this->inject->Name = L"inject";
			this->inject->Size = System::Drawing::Size(110, 50);
			this->inject->TabIndex = 0;
			this->inject->Text = L"Inject";
			this->inject->UseVisualStyleBackColor = true;
			this->inject->Click += gcnew System::EventHandler(this, &Form1::inject_Click);
			// 
			// txtActivated
			// 
			this->txtActivated->AutoSize = true;
			this->txtActivated->Location = System::Drawing::Point(68, 71);
			this->txtActivated->Name = L"txtActivated";
			this->txtActivated->Padding = System::Windows::Forms::Padding(15);
			this->txtActivated->Size = System::Drawing::Size(142, 46);
			this->txtActivated->TabIndex = 1;
			this->txtActivated->Text = L"Click inject to start";
			// 
			// leaveappopen
			// 
			this->leaveappopen->AutoSize = true;
			this->leaveappopen->Location = System::Drawing::Point(64, 126);
			this->leaveappopen->Name = L"leaveappopen";
			this->leaveappopen->Size = System::Drawing::Size(0, 16);
			this->leaveappopen->TabIndex = 2;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 253);
			this->Controls->Add(this->leaveappopen);
			this->Controls->Add(this->txtActivated);
			this->Controls->Add(this->inject);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(300, 300);
			this->MinimumSize = System::Drawing::Size(300, 300);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

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
	};
}
