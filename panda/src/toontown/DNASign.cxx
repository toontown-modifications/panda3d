#include "DNASign.h"

#include "modelNode.h"
#include "decalEffect.h"

TypeHandle DNASign::_type_handle;

DNASign::DNASign(const std::string& name): DNAProp(name)
{
}

DNASign::~DNASign()
{
}

void DNASign::make_from_dgi(DatagramIterator& dgi, DNAStorage* store)
{
    DNAProp::make_from_dgi(dgi, store);
}

void DNASign::traverse(NodePath& np, DNAStorage* store)
{
    NodePath decal_node, _np, origin;
    decal_node = np.find("**/sign_decal");
    if (decal_node.is_empty())
        decal_node = np.find("**/*_front");

    if (!decal_node.node()->is_geom_node())
        decal_node = decal_node.find("**/+GeomNode");

    if (decal_node.is_empty())
        decal_node = np.find("**/+GeomNode");

    decal_node.set_effect(DecalEffect::make());

    PT(ModelNode) node = new ModelNode("sign");
    _np = decal_node.attach_new_node(node);

    if (m_code.size())
    {
        _np = store->find_node(m_code).copy_to(_np);
        _np.set_name("sign");
    }

    std::string np_name = np.get_name();
    if (np_name.find("linktunnel_") != std::string::npos && np_name.find("hq_") != std::string::npos)
        m_pos[1] -= 0.45;
    else
        m_pos[1] -= 0.05;

    block_number_t block_number = atoi(store->get_block(np_name).c_str());
    zone_id_t zone_id = store->get_zone_from_block_number(block_number);
    bool use_origin_mat = false;
    if (!(zone_id % 1000 == 0 && zone_id < 61000))
    {
        int bad_blocks[] = {1606, 1609, 1614, 1615, 1621, 1707, 1710, 1713,
                            1718, 1719, 1724, 1806, 1808, 1814, 1818, 1825,
                            1830, 2626, 2629, 2633, 2639, 2643, 2649, 2729,
                            2734, 2739, 2740, 2829, 2839};
        if (zone_id == 0)
            zone_id = 2000;
        else if (zone_id >= 22000 && zone_id < 61000)
        {
            zone_id = zone_id % 2000;
            if (zone_id < 1000)
                zone_id = zone_id + 2000;
            else
                zone_id = zone_id - 1000 + 8000;
        }

        int branch_id = zone_id - zone_id % 100;
        if (zone_id % 1000 >= 500)
            branch_id -= 500;

        int interior_zone_id = branch_id + block_number + 500;
        if (std::find(std::begin(bad_blocks), std::end(bad_blocks), interior_zone_id) != std::end(bad_blocks))
            use_origin_mat = true;
    }

    origin = np.find("**/*sign_origin");
    _np.set_pos_hpr_scale(origin, m_pos, m_hpr, m_scale);
    _np.set_color(m_color);
    _np.wrt_reparent_to(origin, 0);
    traverse_children(_np, store);
    _np.flatten_strong();
    node->set_preserve_transform(ModelNode::PT_net);

    LMatrix4f mat;
    if (use_origin_mat)
        mat = origin.get_transform()->get_mat();
    else
        mat = _np.get_transform()->get_mat();

    store->store_block_sign_transform(block_number, mat);
}
