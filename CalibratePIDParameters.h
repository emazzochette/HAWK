#pragma once

#include <comdef.h>
#include <windows.h>

#pragma managed(push,off)
#include <cv.h>
#pragma managed(pop)

#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

#include "Stimulus.h"
#include "STM_Communicator.h"


namespace BehaviorRig20 {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for CalibratePIDParameters
	/// </summary>
	public ref class CalibratePIDParameters : public System::Windows::Forms::Form
	{
	public:
		CalibratePIDParameters(STM_Communicator* comm)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->comm = comm;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CalibratePIDParameters()
		{
			if (components)
			{
				delete components;
			}
		}

	private: STM_Communicator* comm;
	private: System::Windows::Forms::GroupBox^  clampModeGroupBox;
	private: System::Windows::Forms::RadioButton^  forceClampRadioButton;
	private: System::Windows::Forms::RadioButton^  displacementClampRadioButton;
	private: System::Windows::Forms::NumericUpDown^  kuNumericUpDown;
	private: System::Windows::Forms::NumericUpDown^  tuNumericUpDown;


	private: System::Windows::Forms::Label^  pParameterLabel;
	private: System::Windows::Forms::Label^  periodLabel;
	private: System::Windows::Forms::Button^  startCalibrationButton;
	private: System::Windows::Forms::Button^  calculateParametersButton;
	private: System::Windows::Forms::Label^  pEquationLabel;

	private: System::Windows::Forms::Label^  iEquationLabel;
	private: System::Windows::Forms::Label^  dEquationLabel;



	private: System::Windows::Forms::GroupBox^  calculatedParametersGroupBox;
	private: System::Windows::Forms::Button^  cancelCalibrationButton;
	private: System::Windows::Forms::Button^  finishCalibrationButton;
	private: System::Windows::Forms::NumericUpDown^  dParameterNumericUpDown;

	private: System::Windows::Forms::NumericUpDown^  iParameterNumericUpDown;

	private: System::Windows::Forms::NumericUpDown^  pParameterNumericUpDown;
	private: System::Windows::Forms::Button^  testParametersButton;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  signalChart;
	private: System::Windows::Forms::Button^  getDataButton;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TextBox^  cantileverIDTextBox;
	private: System::Windows::Forms::Label^  cantileverIDLabel;
	private: System::Windows::Forms::CheckBox^  recordDataCheckBox;
	private: System::Windows::Forms::TextBox^  dataCommentsTextBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  voltageNumericUpDown;
	private: System::Windows::Forms::NumericUpDown^  durationNumericUpDown;
	private: System::Windows::Forms::Label^  voltageLabel;
	private: System::Windows::Forms::Label^  durationLabel;
	private: System::Windows::Forms::Label^  voltageUnitLabel;
	private: System::Windows::Forms::Label^  durationUnitLabel;




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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(CalibratePIDParameters::typeid));
			this->clampModeGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->forceClampRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->displacementClampRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->kuNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->tuNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->pParameterLabel = (gcnew System::Windows::Forms::Label());
			this->periodLabel = (gcnew System::Windows::Forms::Label());
			this->startCalibrationButton = (gcnew System::Windows::Forms::Button());
			this->calculateParametersButton = (gcnew System::Windows::Forms::Button());
			this->pEquationLabel = (gcnew System::Windows::Forms::Label());
			this->iEquationLabel = (gcnew System::Windows::Forms::Label());
			this->dEquationLabel = (gcnew System::Windows::Forms::Label());
			this->calculatedParametersGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->dParameterNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->iParameterNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->pParameterNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->cancelCalibrationButton = (gcnew System::Windows::Forms::Button());
			this->finishCalibrationButton = (gcnew System::Windows::Forms::Button());
			this->testParametersButton = (gcnew System::Windows::Forms::Button());
			this->signalChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->getDataButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->cantileverIDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->cantileverIDLabel = (gcnew System::Windows::Forms::Label());
			this->recordDataCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->dataCommentsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->voltageNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->durationNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->voltageLabel = (gcnew System::Windows::Forms::Label());
			this->durationLabel = (gcnew System::Windows::Forms::Label());
			this->voltageUnitLabel = (gcnew System::Windows::Forms::Label());
			this->durationUnitLabel = (gcnew System::Windows::Forms::Label());
			this->clampModeGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->kuNumericUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tuNumericUpDown))->BeginInit();
			this->calculatedParametersGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dParameterNumericUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->iParameterNumericUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pParameterNumericUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->signalChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->voltageNumericUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->durationNumericUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// clampModeGroupBox
			// 
			this->clampModeGroupBox->Controls->Add(this->forceClampRadioButton);
			this->clampModeGroupBox->Controls->Add(this->displacementClampRadioButton);
			this->clampModeGroupBox->Location = System::Drawing::Point(13, 13);
			this->clampModeGroupBox->Name = L"clampModeGroupBox";
			this->clampModeGroupBox->Size = System::Drawing::Size(135, 70);
			this->clampModeGroupBox->TabIndex = 0;
			this->clampModeGroupBox->TabStop = false;
			this->clampModeGroupBox->Text = L"Select Clamp Mode:";
			// 
			// forceClampRadioButton
			// 
			this->forceClampRadioButton->AutoSize = true;
			this->forceClampRadioButton->Location = System::Drawing::Point(7, 44);
			this->forceClampRadioButton->Name = L"forceClampRadioButton";
			this->forceClampRadioButton->Size = System::Drawing::Size(84, 17);
			this->forceClampRadioButton->TabIndex = 1;
			this->forceClampRadioButton->TabStop = true;
			this->forceClampRadioButton->Text = L"Force Clamp";
			this->forceClampRadioButton->UseVisualStyleBackColor = true;
			// 
			// displacementClampRadioButton
			// 
			this->displacementClampRadioButton->AutoSize = true;
			this->displacementClampRadioButton->Location = System::Drawing::Point(7, 20);
			this->displacementClampRadioButton->Name = L"displacementClampRadioButton";
			this->displacementClampRadioButton->Size = System::Drawing::Size(121, 17);
			this->displacementClampRadioButton->TabIndex = 0;
			this->displacementClampRadioButton->TabStop = true;
			this->displacementClampRadioButton->Text = L"Displacement Clamp";
			this->displacementClampRadioButton->UseVisualStyleBackColor = true;
			// 
			// kuNumericUpDown
			// 
			this->kuNumericUpDown->DecimalPlaces = 2;
			this->kuNumericUpDown->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 131072});
			this->kuNumericUpDown->Location = System::Drawing::Point(183, 26);
			this->kuNumericUpDown->Name = L"kuNumericUpDown";
			this->kuNumericUpDown->Size = System::Drawing::Size(120, 20);
			this->kuNumericUpDown->TabIndex = 1;
			// 
			// tuNumericUpDown
			// 
			this->tuNumericUpDown->DecimalPlaces = 5;
			this->tuNumericUpDown->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 131072});
			this->tuNumericUpDown->Location = System::Drawing::Point(183, 52);
			this->tuNumericUpDown->Name = L"tuNumericUpDown";
			this->tuNumericUpDown->Size = System::Drawing::Size(120, 20);
			this->tuNumericUpDown->TabIndex = 2;
			// 
			// pParameterLabel
			// 
			this->pParameterLabel->AutoSize = true;
			this->pParameterLabel->Location = System::Drawing::Point(159, 28);
			this->pParameterLabel->Name = L"pParameterLabel";
			this->pParameterLabel->Size = System::Drawing::Size(23, 13);
			this->pParameterLabel->TabIndex = 3;
			this->pParameterLabel->Text = L"Ku:";
			// 
			// periodLabel
			// 
			this->periodLabel->AutoSize = true;
			this->periodLabel->Location = System::Drawing::Point(159, 55);
			this->periodLabel->Name = L"periodLabel";
			this->periodLabel->Size = System::Drawing::Size(23, 13);
			this->periodLabel->TabIndex = 4;
			this->periodLabel->Text = L"Tu:";
			// 
			// startCalibrationButton
			// 
			this->startCalibrationButton->Location = System::Drawing::Point(316, 19);
			this->startCalibrationButton->Name = L"startCalibrationButton";
			this->startCalibrationButton->Size = System::Drawing::Size(132, 23);
			this->startCalibrationButton->TabIndex = 5;
			this->startCalibrationButton->Text = L"Start Calibration";
			this->startCalibrationButton->UseVisualStyleBackColor = true;
			this->startCalibrationButton->Click += gcnew System::EventHandler(this, &CalibratePIDParameters::startCalibrationButton_Click);
			// 
			// calculateParametersButton
			// 
			this->calculateParametersButton->Location = System::Drawing::Point(316, 49);
			this->calculateParametersButton->Name = L"calculateParametersButton";
			this->calculateParametersButton->Size = System::Drawing::Size(132, 23);
			this->calculateParametersButton->TabIndex = 6;
			this->calculateParametersButton->Text = L"Calculate Parameters";
			this->calculateParametersButton->UseVisualStyleBackColor = true;
			this->calculateParametersButton->Click += gcnew System::EventHandler(this, &CalibratePIDParameters::calculateParametersButton_Click);
			// 
			// pEquationLabel
			// 
			this->pEquationLabel->AutoSize = true;
			this->pEquationLabel->Location = System::Drawing::Point(18, 15);
			this->pEquationLabel->Name = L"pEquationLabel";
			this->pEquationLabel->Size = System::Drawing::Size(70, 13);
			this->pEquationLabel->TabIndex = 7;
			this->pEquationLabel->Text = L"P = 0.6*Ku = ";
			// 
			// iEquationLabel
			// 
			this->iEquationLabel->AutoSize = true;
			this->iEquationLabel->Location = System::Drawing::Point(18, 40);
			this->iEquationLabel->Name = L"iEquationLabel";
			this->iEquationLabel->Size = System::Drawing::Size(75, 13);
			this->iEquationLabel->TabIndex = 8;
			this->iEquationLabel->Text = L"I = (2*P/Tu) = ";
			// 
			// dEquationLabel
			// 
			this->dEquationLabel->AutoSize = true;
			this->dEquationLabel->Location = System::Drawing::Point(17, 63);
			this->dEquationLabel->Name = L"dEquationLabel";
			this->dEquationLabel->Size = System::Drawing::Size(74, 13);
			this->dEquationLabel->TabIndex = 9;
			this->dEquationLabel->Text = L"D = P*Tu/8 = ";
			// 
			// calculatedParametersGroupBox
			// 
			this->calculatedParametersGroupBox->Controls->Add(this->dParameterNumericUpDown);
			this->calculatedParametersGroupBox->Controls->Add(this->iParameterNumericUpDown);
			this->calculatedParametersGroupBox->Controls->Add(this->pParameterNumericUpDown);
			this->calculatedParametersGroupBox->Controls->Add(this->pEquationLabel);
			this->calculatedParametersGroupBox->Controls->Add(this->iEquationLabel);
			this->calculatedParametersGroupBox->Controls->Add(this->dEquationLabel);
			this->calculatedParametersGroupBox->Location = System::Drawing::Point(13, 89);
			this->calculatedParametersGroupBox->Name = L"calculatedParametersGroupBox";
			this->calculatedParametersGroupBox->Size = System::Drawing::Size(234, 88);
			this->calculatedParametersGroupBox->TabIndex = 13;
			this->calculatedParametersGroupBox->TabStop = false;
			this->calculatedParametersGroupBox->Text = L"Calculated Parameters:";
			// 
			// dParameterNumericUpDown
			// 
			this->dParameterNumericUpDown->DecimalPlaces = 9;
			this->dParameterNumericUpDown->Location = System::Drawing::Point(98, 60);
			this->dParameterNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->dParameterNumericUpDown->Name = L"dParameterNumericUpDown";
			this->dParameterNumericUpDown->Size = System::Drawing::Size(120, 20);
			this->dParameterNumericUpDown->TabIndex = 12;
			// 
			// iParameterNumericUpDown
			// 
			this->iParameterNumericUpDown->DecimalPlaces = 9;
			this->iParameterNumericUpDown->Location = System::Drawing::Point(98, 37);
			this->iParameterNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000, 0, 0, 0});
			this->iParameterNumericUpDown->Name = L"iParameterNumericUpDown";
			this->iParameterNumericUpDown->Size = System::Drawing::Size(120, 20);
			this->iParameterNumericUpDown->TabIndex = 11;
			// 
			// pParameterNumericUpDown
			// 
			this->pParameterNumericUpDown->DecimalPlaces = 5;
			this->pParameterNumericUpDown->Location = System::Drawing::Point(98, 13);
			this->pParameterNumericUpDown->Name = L"pParameterNumericUpDown";
			this->pParameterNumericUpDown->Size = System::Drawing::Size(120, 20);
			this->pParameterNumericUpDown->TabIndex = 10;
			// 
			// cancelCalibrationButton
			// 
			this->cancelCalibrationButton->Location = System::Drawing::Point(611, 214);
			this->cancelCalibrationButton->Name = L"cancelCalibrationButton";
			this->cancelCalibrationButton->Size = System::Drawing::Size(75, 23);
			this->cancelCalibrationButton->TabIndex = 14;
			this->cancelCalibrationButton->Text = L"Cancel";
			this->cancelCalibrationButton->UseVisualStyleBackColor = true;
			this->cancelCalibrationButton->Click += gcnew System::EventHandler(this, &CalibratePIDParameters::cancelCalibrationButton_Click);
			// 
			// finishCalibrationButton
			// 
			this->finishCalibrationButton->Location = System::Drawing::Point(530, 214);
			this->finishCalibrationButton->Name = L"finishCalibrationButton";
			this->finishCalibrationButton->Size = System::Drawing::Size(75, 23);
			this->finishCalibrationButton->TabIndex = 15;
			this->finishCalibrationButton->Text = L"OK";
			this->finishCalibrationButton->UseVisualStyleBackColor = true;
			this->finishCalibrationButton->Click += gcnew System::EventHandler(this, &CalibratePIDParameters::finishCalibrationButton_Click);
			// 
			// testParametersButton
			// 
			this->testParametersButton->Location = System::Drawing::Point(434, 111);
			this->testParametersButton->Name = L"testParametersButton";
			this->testParametersButton->Size = System::Drawing::Size(130, 23);
			this->testParametersButton->TabIndex = 16;
			this->testParametersButton->Text = L"Apply Test Pulse";
			this->testParametersButton->UseVisualStyleBackColor = true;
			this->testParametersButton->Click += gcnew System::EventHandler(this, &CalibratePIDParameters::testParametersButton_Click);
			// 
			// signalChart
			// 
			chartArea1->AxisX->Title = L"Time (s)";
			chartArea1->Name = L"ChartArea1";
			this->signalChart->ChartAreas->Add(chartArea1);
			this->signalChart->Location = System::Drawing::Point(13, 243);
			this->signalChart->Name = L"signalChart";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Name = L"Signal";
			this->signalChart->Series->Add(series1);
			this->signalChart->Size = System::Drawing::Size(673, 148);
			this->signalChart->TabIndex = 17;
			this->signalChart->Text = L"signalChart";
			// 
			// getDataButton
			// 
			this->getDataButton->Location = System::Drawing::Point(434, 146);
			this->getDataButton->Name = L"getDataButton";
			this->getDataButton->Size = System::Drawing::Size(130, 23);
			this->getDataButton->TabIndex = 18;
			this->getDataButton->Text = L"Get Data";
			this->getDataButton->UseVisualStyleBackColor = true;
			this->getDataButton->Click += gcnew System::EventHandler(this, &CalibratePIDParameters::getDataButton_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(13, 397);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(623, 143);
			this->pictureBox1->TabIndex = 19;
			this->pictureBox1->TabStop = false;
			// 
			// cantileverIDTextBox
			// 
			this->cantileverIDTextBox->Location = System::Drawing::Point(467, 52);
			this->cantileverIDTextBox->Name = L"cantileverIDTextBox";
			this->cantileverIDTextBox->Size = System::Drawing::Size(190, 20);
			this->cantileverIDTextBox->TabIndex = 20;
			// 
			// cantileverIDLabel
			// 
			this->cantileverIDLabel->AutoSize = true;
			this->cantileverIDLabel->Location = System::Drawing::Point(467, 32);
			this->cantileverIDLabel->Name = L"cantileverIDLabel";
			this->cantileverIDLabel->Size = System::Drawing::Size(71, 13);
			this->cantileverIDLabel->TabIndex = 21;
			this->cantileverIDLabel->Text = L"Cantilever ID:";
			this->cantileverIDLabel->UseMnemonic = false;
			// 
			// recordDataCheckBox
			// 
			this->recordDataCheckBox->AutoSize = true;
			this->recordDataCheckBox->Location = System::Drawing::Point(570, 148);
			this->recordDataCheckBox->Name = L"recordDataCheckBox";
			this->recordDataCheckBox->Size = System::Drawing::Size(87, 17);
			this->recordDataCheckBox->TabIndex = 22;
			this->recordDataCheckBox->Text = L"Record Data";
			this->recordDataCheckBox->UseVisualStyleBackColor = true;
			// 
			// dataCommentsTextBox
			// 
			this->dataCommentsTextBox->Location = System::Drawing::Point(147, 180);
			this->dataCommentsTextBox->Multiline = true;
			this->dataCommentsTextBox->Name = L"dataCommentsTextBox";
			this->dataCommentsTextBox->Size = System::Drawing::Size(245, 33);
			this->dataCommentsTextBox->TabIndex = 23;
			this->dataCommentsTextBox->TextChanged += gcnew System::EventHandler(this, &CalibratePIDParameters::dataCommentsTextBox_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 180);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(119, 13);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Comments for Data File:";
			// 
			// voltageNumericUpDown
			// 
			this->voltageNumericUpDown->DecimalPlaces = 3;
			this->voltageNumericUpDown->Location = System::Drawing::Point(253, 111);
			this->voltageNumericUpDown->Name = L"voltageNumericUpDown";
			this->voltageNumericUpDown->Size = System::Drawing::Size(120, 20);
			this->voltageNumericUpDown->TabIndex = 25;
			// 
			// durationNumericUpDown
			// 
			this->durationNumericUpDown->DecimalPlaces = 3;
			this->durationNumericUpDown->Location = System::Drawing::Point(253, 150);
			this->durationNumericUpDown->Name = L"durationNumericUpDown";
			this->durationNumericUpDown->Size = System::Drawing::Size(120, 20);
			this->durationNumericUpDown->TabIndex = 26;
			// 
			// voltageLabel
			// 
			this->voltageLabel->AutoSize = true;
			this->voltageLabel->Location = System::Drawing::Point(253, 92);
			this->voltageLabel->Name = L"voltageLabel";
			this->voltageLabel->Size = System::Drawing::Size(46, 13);
			this->voltageLabel->TabIndex = 27;
			this->voltageLabel->Text = L"Voltage:";
			// 
			// durationLabel
			// 
			this->durationLabel->AutoSize = true;
			this->durationLabel->Location = System::Drawing::Point(253, 134);
			this->durationLabel->Name = L"durationLabel";
			this->durationLabel->Size = System::Drawing::Size(50, 13);
			this->durationLabel->TabIndex = 28;
			this->durationLabel->Text = L"Duration:";
			// 
			// voltageUnitLabel
			// 
			this->voltageUnitLabel->AutoSize = true;
			this->voltageUnitLabel->Location = System::Drawing::Point(379, 113);
			this->voltageUnitLabel->Name = L"voltageUnitLabel";
			this->voltageUnitLabel->Size = System::Drawing::Size(14, 13);
			this->voltageUnitLabel->TabIndex = 29;
			this->voltageUnitLabel->Text = L"V";
			// 
			// durationUnitLabel
			// 
			this->durationUnitLabel->AutoEllipsis = true;
			this->durationUnitLabel->AutoSize = true;
			this->durationUnitLabel->Location = System::Drawing::Point(379, 152);
			this->durationUnitLabel->Name = L"durationUnitLabel";
			this->durationUnitLabel->Size = System::Drawing::Size(12, 13);
			this->durationUnitLabel->TabIndex = 30;
			this->durationUnitLabel->Text = L"s";
			// 
			// CalibratePIDParameters
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(698, 552);
			this->Controls->Add(this->durationUnitLabel);
			this->Controls->Add(this->voltageUnitLabel);
			this->Controls->Add(this->durationLabel);
			this->Controls->Add(this->voltageLabel);
			this->Controls->Add(this->durationNumericUpDown);
			this->Controls->Add(this->voltageNumericUpDown);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataCommentsTextBox);
			this->Controls->Add(this->recordDataCheckBox);
			this->Controls->Add(this->cantileverIDLabel);
			this->Controls->Add(this->cantileverIDTextBox);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->getDataButton);
			this->Controls->Add(this->signalChart);
			this->Controls->Add(this->testParametersButton);
			this->Controls->Add(this->finishCalibrationButton);
			this->Controls->Add(this->cancelCalibrationButton);
			this->Controls->Add(this->calculateParametersButton);
			this->Controls->Add(this->startCalibrationButton);
			this->Controls->Add(this->periodLabel);
			this->Controls->Add(this->pParameterLabel);
			this->Controls->Add(this->tuNumericUpDown);
			this->Controls->Add(this->kuNumericUpDown);
			this->Controls->Add(this->clampModeGroupBox);
			this->Controls->Add(this->calculatedParametersGroupBox);
			this->Name = L"CalibratePIDParameters";
			this->Text = L"Calibrate PID Parameters";
			this->clampModeGroupBox->ResumeLayout(false);
			this->clampModeGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->kuNumericUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tuNumericUpDown))->EndInit();
			this->calculatedParametersGroupBox->ResumeLayout(false);
			this->calculatedParametersGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dParameterNumericUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->iParameterNumericUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pParameterNumericUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->signalChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->voltageNumericUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->durationNumericUpDown))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void startCalibrationButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Stimulus stim = createStimulus();
		//covert to an array of voltage doubles
		int size = stim.waveTable.size();
		double* stimVoltages = new double[size];
		for (int i = 0; i < size; i++) {
			double value = stim.voltages[i] ;
			stimVoltages[i] = value;
		}

		comm->sendWaveTable(stimVoltages, size);
		delete stimVoltages;

		stim.totalPoints = stim.waveTable.size();
		stim.totalTime = stim.totalPoints/DELTA_T;
		
		// send all the data to the FPGA:
		//Wave interval - spacing between points on wave table
		comm->sendWaveInterval((int)(DELTA_T*1000000)); // need to convert from s to us for this
		Threading::Thread::Sleep(500);

		//Send PID parameters:
		int numParams = 4;
		double* parameters = new double[numParams];
		parameters[0] = Decimal::ToDouble(kuNumericUpDown->Value);
		parameters[1] = 0;
		parameters[2] = 0;
		parameters[3] = 5; //need to make sure this parameter is OK.
		comm->sendPIDParameters(parameters, numParams);
		Threading::Thread::Sleep(500);

		if (forceClampRadioButton->Checked){
			comm->sendClampMode(2);
		}
		else if (displacementClampRadioButton->Checked){
			//Send Clamp Mode: Displacement Clamp
			comm->sendClampMode(1);
		}
		else {
			MessageBox::Show("Please select a clamp mode");
			return;
			
		}
		Threading::Thread::Sleep(500);
			//Send all the data to FPGA, request info back
		//Send trigger mode
		comm->sendTriggerMode(1);
		//Send data acquisition parameter
		Threading::Thread::Sleep(500);
		comm->sendAcquisitionInterval(1000); // number of us between two points "1000" = 1kHz sampling, min value this can be is 100 ("100" = 10 kHz)
		Threading::Thread::Sleep(500);
		comm->triggerStimulus();

	}
private: System::Void calculateParametersButton_Click(System::Object^  sender, System::EventArgs^  e) {
		double pParameter = Decimal::ToDouble(kuNumericUpDown->Value)*0.6;
		double iParameter = 2*pParameter/Decimal::ToDouble(tuNumericUpDown->Value);
		double dParameter = pParameter*Decimal::ToDouble(tuNumericUpDown->Value)/8;
	    pParameterNumericUpDown->Value = Decimal(pParameter);
		iParameterNumericUpDown->Value = Decimal(iParameter);
		dParameterNumericUpDown->Value = Decimal(dParameter);
	}
private: System::Void finishCalibrationButton_Click(System::Object^  sender, System::EventArgs^  e) {
			this->DialogResult = Windows::Forms::DialogResult::OK;
			this->Close();
	}
private: System::Void cancelCalibrationButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->DialogResult = Windows::Forms::DialogResult::Cancel;
			this->Close();
	}

Stimulus createStimulus(void)
	{
		double maxSignal = 0;
		double contactTime = 100;
		double period = 5;
		int noCycles = 1;
		double scale = 0;
		double magnitude = maxSignal;
		int scaleType = 0;
		double sineFreq = 0;
		double sineBias = 0;
		double zeroPulse = 2;

		Stimulus stim(period, contactTime, noCycles, magnitude, scale, scaleType, sineFreq, sineBias, zeroPulse);

		stim.createCalibrationWaveTable();
				
		stim.appendZeroPulse(zeroPulse);

		stim.convertToVoltages(1/ACTUATOR_SENSITIVITY);
		


		return stim;
	}

private: System::Void testParametersButton_Click(System::Object^  sender, System::EventArgs^  e) {
		double magnitude;
		if (forceClampRadioButton->Checked){
			magnitude = Decimal::ToDouble(voltageNumericUpDown->Value); // this is the voltage we want to clamp onto, not the force.
		}
		else {
			magnitude = 40; // 
		}
		double duration = Decimal::ToDouble(durationNumericUpDown->Value);
		Stimulus stim = createTestStimulus(magnitude,duration);
		
		//covert to an array of voltage doubles
		int size = stim.waveTable.size();
		double* stimVoltages = new double[size];
		for (int i = 0; i < size; i++) {
			double value = stim.voltages[i] ;
			stimVoltages[i] = value;
		}

		comm->sendWaveTable(stimVoltages, size);
		delete stimVoltages; 

		stim.totalPoints = stim.waveTable.size();
		stim.totalTime = stim.totalPoints/DELTA_T;
		
		// send all the data to the FPGA:
		//Wave interval - spacing between points on wave table
		comm->sendWaveInterval((int)(DELTA_T*1000000)); // need to convert from s to us for this
		Threading::Thread::Sleep(500);

		//Send PID parameters:
		int numParams = 4;
		double* parameters = new double[numParams];
		parameters[0] = Decimal::ToDouble(pParameterNumericUpDown->Value);
		parameters[1] = Decimal::ToDouble(iParameterNumericUpDown->Value);
		parameters[2] = Decimal::ToDouble(dParameterNumericUpDown->Value);
		parameters[3] = 5; //need to make sure this parameter is OK.
		comm->sendPIDParameters(parameters, numParams);
		Threading::Thread::Sleep(500);

		if (forceClampRadioButton->Checked){
			comm->sendClampMode(2);
		}
		else if (displacementClampRadioButton->Checked){
			//Send Clamp Mode: Displacement Clamp
			comm->sendClampMode(1);
		}
		else {
			MessageBox::Show("Please select a clamp mode");
			return;
			
		}
		Threading::Thread::Sleep(500);
			//Send all the data to FPGA, request info back
		//Send trigger mode
		comm->sendTriggerMode(1);
		//Send data acquisition parameter
		Threading::Thread::Sleep(500);
		comm->sendAcquisitionInterval(1000); // number of us between two points "1000" = 1kHz sampling, min value this can be is 100 ("100" = 10 kHz)
		Threading::Thread::Sleep(500);
		comm->triggerStimulus();
		
	 }
private: System::Void getDataButton_Click(System::Object^  sender, System::EventArgs^  e) {
		//gather data, write to plots:
		signalChart->Series["Signal"]->Points->Clear();
		
		vector<double> actuatorPositionSignal = comm->actuatorPositionData;
		vector<double> cantileverSignal = comm->piezoSignalData;
		vector<double> actuatorCommandSignal = comm->actuatorCommandData;
		vector<double> desiredSignal = comm->desiredSignalData;
		
		if (recordDataCheckBox->Checked){
			marshal_context^ context = gcnew marshal_context();
			string cantileverID = context->marshal_as<string>(cantileverIDTextBox->Text);
			string commentsForData = context->marshal_as<string>(dataCommentsTextBox->Text);
			vector<double> PIDParameters;
			PIDParameters.push_back(Decimal::ToDouble(pParameterNumericUpDown->Value));
			PIDParameters.push_back(Decimal::ToDouble(iParameterNumericUpDown->Value));
			PIDParameters.push_back(Decimal::ToDouble(dParameterNumericUpDown->Value)); 
			writeCalibrationDataToDisk( actuatorPositionSignal,  cantileverSignal,  actuatorCommandSignal, desiredSignal,  cantileverID,  commentsForData, PIDParameters);
			PIDParameters.clear();
		}


		vector<double> signal; 
		if (displacementClampRadioButton->Checked)
			signal = comm->actuatorPositionData;
		else 
			signal = comm->piezoSignalData;
	
		
		int size = signal.size();
		
		//plot on chart
		for (int i = 0; i < size; i++) {
			double value = signal[i];
			signalChart->Series["Signal"]->Points->AddXY(i * DELTA_T, value);
		}

	}

Stimulus createTestStimulus(double magnitude, double duration)
	{
		double contactTime = 100;
		//double period = 0.1;
		int noCycles = 1;
		double scale = 0;
		int scaleType = 0;
		double sineFreq = 0;
		double sineBias = 0;
		double zeroPulse = 1;

		Stimulus stim(duration, contactTime, noCycles, magnitude, scale, scaleType, sineFreq, sineBias, zeroPulse);
		
		//stim.prependZeroPulse(1000);

		stim.createSquare();
				
		stim.appendZeroPulse(zeroPulse);
		
		if (forceClampRadioButton->Checked)
			stim.convertToVoltages(1);
		else 
			stim.convertToVoltages(1/ACTUATOR_SENSITIVITY);
	


		return stim;
	}


void writeCalibrationDataToDisk(vector<double> actuatorPositions, vector<double> cantileverSignal,  vector<double> actuatorCommandSignal, vector<double> desiredSignal, string cantileverID, string commentsForData, vector<double> PIDParameters){
			cv::FileStorage dataWriter;
			 
			 SYSTEMTIME now;
			GetLocalTime(&now);

			string time;
			char* cTime = new char[50];
			sprintf(cTime, "%04d_%02d_%02d__%02d_%02d_%02d__", now.wYear, now.wMonth, now.wDay, now.wHour, now.wMinute, now.wSecond);
			time = string(cTime);
			delete cTime;

			//string directory = string("C:\\\\Users\\\\HAWK\\\\Documents\\\\CantileverCalibrationData\\\\");
			//string fileName = cantileverID + string("_") + time + string("_PIDData.yaml");
			//string fullfile = directory + fileName;

			string directory = string("C:\\\\Users\\\\HAWK\\\\Documents\\\\CantileverCalibrationData\\\\PIDParameterData\\\\");
			CreateDirectoryA((directory + cantileverID + string("\\\\")).c_str(), NULL);
			string fileName =  time + string("_") + cantileverID + string("_PIDData.yaml");
			string fullfile = directory + cantileverID + string("\\\\") + fileName;
			
			
			dataWriter.open(fullfile, cv::FileStorage::WRITE);

			dataWriter << string("Time") << time;
			dataWriter << string("Cantilever") << cantileverID;
			dataWriter << string("p Parameter") << PIDParameters[0];
			dataWriter << string("i Parameter") << PIDParameters[1];
			dataWriter << string("d Parameter") << PIDParameters[2];
			dataWriter << string("Comments") << commentsForData;
			string nodeTitle;
			char* title = new char[50];
			//Write actuator position:
			dataWriter << "Actuator Position Signal" << "{";
			//print rest of data
			for (unsigned int i = 0; i < actuatorPositions.size(); i++) {
				sprintf(title, "Point %d", i);
				nodeTitle = string(title);
				dataWriter << nodeTitle <<  actuatorPositions[i];
			}
			dataWriter << "}";
			//Write cantilever signal:
			dataWriter << "Cantilever Signal" << "{";
			//print rest of data
			for (unsigned int i = 0; i < cantileverSignal.size(); i++) {
				sprintf(title, "Point %d", i);
				nodeTitle = string(title);
				dataWriter << nodeTitle <<  cantileverSignal[i];
			}
			dataWriter << "}";
			//Write Actuator Commands:
			dataWriter << "Actuator Command Signal" << "{";
			//print rest of data
			for (unsigned int i = 0; i < actuatorCommandSignal.size(); i++) {
				sprintf(title, "Point %d", i);
				nodeTitle = string(title);
				dataWriter << nodeTitle <<  actuatorCommandSignal[i];
			}
			dataWriter << "}";
			//Write desired signal
			dataWriter << "Desired Signal" << "{";
			//print rest of data
			for (unsigned int i = 0; i < desiredSignal.size(); i++) {
				sprintf(title, "Point %d", i);
				nodeTitle = string(title);
				dataWriter << nodeTitle <<  desiredSignal[i];
			}
			dataWriter << "}";


			dataWriter.release();
		}
private: System::Void dataCommentsTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
