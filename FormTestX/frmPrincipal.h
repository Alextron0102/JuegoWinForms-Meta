#pragma once
#include"VFigura.h"
namespace FormTestX {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmPrincipal
	/// </summary>
	public ref class frmPrincipal : public System::Windows::Forms::Form
	{
	public:
		frmPrincipal(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			arrf = new ArregloFigura();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Graphics^ g;
		ArregloFigura* arrf;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &frmPrincipal::timer1_Tick);
			// 
			// frmPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(915, 438);
			this->Name = L"frmPrincipal";
			this->Text = L"frmPrincipal";
			this->Load += gcnew System::EventHandler(this, &frmPrincipal::frmPrincipal_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmPrincipal::frmPrincipal_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &frmPrincipal::frmPrincipal_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
		this->BackColor = Color::Snow;
		g->Clear(Color::Snow);
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		arrf->dibujar(g);
		arrf->validarLlegada(g);
	}
	private: System::Void frmPrincipal_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Pen^ l1 = gcnew Pen(Color::Black, 3);
		g->DrawLine(l1, 560, 0, 560, 280);
		arrf->AgregarFigura(g);
	}
	private: System::Void frmPrincipal_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Space)
			timer1->Enabled = true;
	}
	};
}
