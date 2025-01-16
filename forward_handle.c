
void fwd_handle_packet(struct packet *pkt) {
    // Lookup hardware entry based on Tunnel ID (TID)
    hw_entry_t *hw_entry = lookup_hw_entry(pkt->tid);

    if (hw_entry == NULL) {
        // If no entry exists, create a new hardware entry and pipeline
        simple_fwd_handle_new_hw(pkt->tid, pkt);
    } else {
        // If entry exists, increase packet counter
        hw_entry->packet_counter++;
    }
}

void simple_fwd_handle_new_hw(uint32_t tid, struct packet *pkt) {
    // Define new pipeline attributes
    doca_flow_pipe_attr_t new_pipe_attr = {0};
    new_pipe_attr.match.tun.gtp.teid = tid;  // Match the packet's Tunnel ID
    new_pipe_attr.action.tun.gtp_teid = tid; // Set Tunnel ID for outgoing packets
    new_pipe_attr.action.forward = NIC_PORT; // Forward to NIC port for hardware offload

    // Create the new hardware entry and pipeline
    doca_flow_pipe_create(&new_pipe_attr);

    // Initialize and store hardware entry
    hw_entry_t *new_entry = create_hw_entry(tid);
    new_entry->packet_counter = 1; // Initialize packet counter
    add_hw_entry_to_table(new_entry);
}

hw_entry_t *lookup_hw_entry(uint32_t tid) {
    // Lookup hardware entry by Tunnel ID
    return find_entry_in_hw_table(tid);
}

void add_hw_entry_to_table(hw_entry_t *entry) {
    // Add new entry to the hardware table
    insert_to_hw_table(entry);
}
