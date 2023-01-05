#ifndef MESH_HPP
#define MESH_HPP

namespace Digiplane {

struct Vertex {
    float x, y, z;
    ABGRColor_t color;
};

using VertexBuffer = std::vector<Vertex>;
using VertexBufferIndices = std::vector<uint16_t>;

using VertexBufferIndices_ptr = std::shared_ptr<VertexBufferIndices>;
using VertexBuffer_ptr = std::shared_ptr<VertexBuffer>;

struct Mesh {
	VertexBuffer vertices;
	VertexBufferIndices vertexIndices;
};

} // Digiplane

#endif // MESH_HPP