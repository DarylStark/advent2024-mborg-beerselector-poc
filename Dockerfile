## Stage 1: build the image

FROM dast1986/slough-dev-dc-cpp:latest as builder

# Set the working directory
WORKDIR /app

# Copy the source code
COPY . .

# Build the source code
RUN cmake -B build -S . && cmake --build build --target app

## Stage 2: create the final image

FROM debian:12.7-slim as final

# Working directory
WORKDIR /opt/beer_selector/

# Copy the pre-built binary file from the previous stage
COPY --from=builder /app/build/app beer_selector

# Command to run the executable
CMD ["./beer_selector"]