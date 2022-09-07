./build/aarch64-softmmu/qemu-system-aarch64  \
        -machine virt,virtualization=true,gic-version=3 \
        -nographic \
        -m size=1024M \
        -cpu cortex-a57  \
        -smp cpus=16 \
        -kernel /home/Image4.4  \
        -hda /home/ppi_benchmark_210928.img \
        -append "root=/dev/vda rw console=ttyAMA0 rdinit=/linuxrc"
