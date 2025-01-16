# 6GUPF
This repository contains the implementation of a 6G UPF (User Plane Function) architecture utilizing NVIDIA DPUs, DOCA Flow API, and VPP-UPF.

## Features
- GTP encapsulation and decapsulation.
- Dynamic pipe creation and management.
- QoS handling with high-priority packet forwarding.

## Getting Started
1. Clone the repository:
   ```bash
   git clone https://github.com/engranaabubakar/6GUPF.git


This project demonstrates the implementation of the 6G User Plane Function (UPF) using DPU and the DOCA Flow API. It showcases packet processing using the Data Processing Unit (DPU), GTP encapsulation and decapsulation, and Quality of Service (QoS) handling.

## Prerequisites

Before building and running the examples, ensure that the following dependencies are installed:

- **VPP UPF** (for User Plane Function processing)
- **DOCA Flow API** (for DPU packet processing)
- **DPDK** (for fast packet processing)

### Install VPP UPF with DPDK

To install VPP UPF with DPDK, follow the instructions provided in the [install_vpp_upf_dpdk repository](https://github.com/s5uishida/install_vpp_upf_dpdk). You can install VPP UPF by running the following commands:

1. Clone the repository:

```bash
git clone https://github.com/s5uishida/install_vpp_upf_dpdk.git
cd install_vpp_upf_dpdk
