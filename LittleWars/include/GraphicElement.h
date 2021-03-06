#pragma once
#include "lws.h"
#include <string>
class GraphicElement
{
public:
	GraphicElement(const std::string Graph, const lws::vector<int> &graph_size, const lws::vector<size_t> &PartNum = lws::vector<int>(1, 1));
	GraphicElement(const std::string Graph);
	virtual ~GraphicElement(void);
	virtual void Draw(const lws::vector<int> &coordinate, double angle, size_t element_num = 0)const;
	int GetGraphSizeX()const{ return graph_size_.x_; }
	int GetGraphSizeY()const{ return graph_size_.y_; }
	size_t GetElementCount()const{ return kElementMax; }
private:
	void SetGraph(const std::string GraphFile, const lws::vector<int> &graph_size, const lws::vector<size_t> &PartNum);
	void SetGraph(const std::string GraphFile);
	int* graph_handle_;
	const size_t kElementMax;
	lws::vector<int> graph_size_;

};

