
class axi_m_agt extends uvm_agent;
    `uvm_component_utils(axi_m_agt)

    virtual interface m_vif;
    axi_m_cfg m_cfg;

    axi_m_driver m_drv;
    axi_m_monitor m_mon;
    axi_m_sequencer m_sqr;

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    extern virtual function void build_phase(uvm_phase phase);
    extern virtual function void connect_phase(uvm_phase phase);

endclass: axi_m_agt

virtual function void axi_m_agt::build_phase(uvm_phase phase);
    m_drv = axi_m_driver::type_id::creat("m_drv");
    m_mon = axi_m_driver::type_id::creat("m_mon");
    m_sqr = axi_m_driver::type_id::creat("m_sqr");
endfunction

virtual function void axi_m_agt::connect_phase(uvm_phase phase);
    m_drv.seq_item_port.connect(m_sqr.seq_item_export);
endfunction

