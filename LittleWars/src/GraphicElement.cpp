#include "..\include\GraphicElement.h"
#include "DxLib.h"


GraphicElement::GraphicElement(const std::string Graph, const lws::vector<int> &graph_size, const lws::vector<size_t> &PartNum) :
	kElementMax((PartNum.x_)*(PartNum.y_))
{
	graph_handle_ = new int[kElementMax]();
	SetGraph(Graph, graph_size, PartNum);
}

GraphicElement::GraphicElement(const std::string Graph):
	kElementMax(1)
{
	graph_handle_ = new int[kElementMax]();
	SetGraph(Graph);
}

GraphicElement::~GraphicElement(void)
{
	for (size_t i = 0; i < kElementMax; i++)
	{
		DeleteGraph(graph_handle_[i]);
	}
	delete[] graph_handle_;
}

void GraphicElement::SetGraph(const std::string GraphFile, const lws::vector<int> &graph_size, const lws::vector<size_t> &PartNum) {
	graph_size_ = graph_size;
	LoadDivGraph(GraphFile.c_str(), (PartNum.x_*PartNum.y_), PartNum.x_, PartNum.y_, graph_size.x_, graph_size.y_, graph_handle_);
}

void GraphicElement::SetGraph(const std::string GraphFile)
{
	graph_handle_[0] = LoadGraph(GraphFile.c_str());
	GetGraphSize(graph_handle_[0], &graph_size_.x_, &graph_size_.y_);
}

void GraphicElement::Draw(const lws::vector<int> &coordinate, double angle, size_t Element_Num)const {
	if (Element_Num <= kElementMax)
	{
		DrawRotaGraph(coordinate.x_, coordinate.y_, 1.0, angle, graph_handle_[Element_Num], true);
	}
}