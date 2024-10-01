## Stage 1: build the image

FROM dast1986/slough-dev-dc-cpp:latest as builder

# Set the working directory
WORKDIR /app

# Copy the source code
COPY . .

# Build the source code
RUN cmake -B build -S . && cmake --build build --target app

## Stage 2: create the final image

FROM alpine:3.18 as final

WORKDIR /opt/beer_selector/

# Install necessary libraries
RUN apk add --no-cache libstdc++ libc6-compat

# Copy the pre-built binary file from the previous stage
COPY --from=builder /app/build/app beer_selector

# Ensure the binary has execute permissions
RUN chmod +x beer_selector

# Verify the binary is copied correctly and has the correct permissions
RUN ls -alF /opt/beer_selector/

# Command to run the executable
CMD ["./beer_selector"]