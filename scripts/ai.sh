#!/bin/bash

# Define the path to the script file
LLM_SCRIPT="pendulum_simulation.py"

# Write the Python code into the script file using a heredoc
cat <<EOF > "$LLM_SCRIPT"
from transformers import AutoModelForCausalLM, AutoTokenizer, pipeline
import torch
import math
import time
import numpy as np
from dotenv import load_dotenv
import os
# from huggingface_hub import login
# from google.colab import userdata
load_dotenv()

# Login to huggingface
# Hugging Face access token 'access-token'
# login(token=userdata.get('HF_TOKEN'), add_to_git_credential=True)  # Disable redundant login sessions

login(token=os.getenv('HF_TOKEN'), add_to_git_credential=True)  # Disable redundant login sessions


# Load the Llama-2-7b model and tokenizer
model_id = "NousResearch/Llama-2-7b-chat-hf"
model = AutoModelForCausalLM.from_pretrained(model_id, torch_dtype=torch.float16, device_map="auto")
tokenizer = AutoTokenizer.from_pretrained(model_id)
chat_pipeline = pipeline("text-generation", model=model, tokenizer=tokenizer)

# Function to generate text using the model
def generate_text(prompt):
    result = chat_pipeline(prompt, max_length=150, num_return_sequences=1, truncation=True)
    return result[0]['generated_text']

# Function to update the pendulum's state based on dynamic parameters
def update_pendulum(angle, angular_velocity, angular_acceleration, length, gravity, deltaTime):
    angular_acceleration = -(gravity / length) * math.sin(angle)
    angular_velocity += angular_acceleration * deltaTime
    angle += angular_velocity * deltaTime

    # Apply damping
    angular_velocity *= 0.99

    # Adding safeguard to prevent runaway values
    if angle > 10:  # Limit angle to avoid too large values
        angle = 10
    if angular_velocity > 50:  # Limit angular velocity to avoid infinite speeds
        angular_velocity = 50

    return angle, angular_velocity, angular_acceleration

# Function to generate the AI explanation with dynamic values
def ai_explanation(angle, angular_velocity, angular_acceleration, length, gravity):
    prompt = f"The pendulum has the following parameters:\n" \
             f"Angle: {angle:.2f} radians\n" \
             f"Angular Velocity: {angular_velocity:.2f} radians per second\n" \
             f"Angular Acceleration: {angular_acceleration:.2f} radians per second^2\n" \
             f"Length: {length:.2f} meters\n" \
             f"Gravity: {gravity:.2f} m/s^2\n\n" \
             f"Explain the motion and physics of the pendulum, including the effects of gravity, length, and the current state of motion."

    # Generate the explanation using the Llama-2 model
    explanation = generate_text(prompt)
    print("\nAI Explanation:")
    print(explanation)

# Function to run the simulation in CLI mode with dynamic inputs
def run_cli_mode():
    print("Running the pendulum simulation in CLI mode...\n")
    
    # Dynamic input for the pendulum properties
    angle = float(input("Enter initial angle (in radians, e.g., 0.785 for 45 degrees): "))
    angular_velocity = float(input("Enter initial angular velocity (in radians per second, e.g., 0.0): "))
    length = float(input("Enter length of the pendulum (in meters, e.g., 2.0): "))
    gravity = float(input("Enter gravitational acceleration (in m/s^2, e.g., 9.8): "))
    deltaTime = float(input("Enter time step (e.g., 0.016 for 60 FPS): "))
    
    # Initialize angular_acceleration to 0.0 
    angular_acceleration = 0.0  
    
    # Simulate for 10 time steps
    for i in range(10):
        angle, angular_velocity, angular_acceleration = update_pendulum(angle, angular_velocity, angular_acceleration, length, gravity, deltaTime)
        ai_explanation(angle, angular_velocity, angular_acceleration, length, gravity)
        print(f"Time step {i}: Angle = {angle:.2f} radians")
        time.sleep(deltaTime)

# Main function
if __name__ == "__main__":
    # Run in CLI mode to take dynamic inputs
    run_cli_mode()

EOF

# Make the script executable
chmod +x "$LLM_SCRIPT"

# Print the path to the script
echo "Python script written to $LLM_SCRIPT"
