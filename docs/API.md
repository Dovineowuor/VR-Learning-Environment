API Documentation for VR Learning Environment

The VR Learning Environment project consists of a set of APIs which enables interaction between application components with other services. The available endpoints, their respective request formats, and their response formats are given here.

## Table of Contents
- [Overview](#overview)
- [Endpoints](#endpoints)
- [Authentication](#authentication)
- [Error Handling](#error-handling)
- [Example Requests and Responses](#example-requests-and-responses)

## Overview

The VR Learning Environment project provides APIs to interact with the platform's backend services, allowing for user management, content delivery, and integration with external tools. These APIs are designed to be simple, efficient, and scalable, following RESTful principles.

## Endpoints

### 1. **User Management API**
   - **/users** (GET)
     - **Description**: Retrieve a list of all users.
     - **Method**: `GET`
- **Parameters**: None
     - **Response**: 
       ```json
       [
         {
           "id": 1,
           "username": "johndoe",
       ```
"email": "johndoe@example.com"
        },
        {
          "id": 2,
          "username": "janedoe",
          "email": "janedoe@example.com"
]
       ```
  
   - **/users/{id}** (GET)
     - **Description**: Returns a record of a single user - by ID
     - **Method**: `GET`
     - **Parameters**:
- `id`: The ID of the user.
     - **Response**: 
       ```json
       {
         "id": 1,
         "username": "johndoe",
         "email": "johndoe@example.com",
"created_at": "2024-01-01T12:00:00Z"
       }
       ```
   - **/users** (POST)
     - **Description**: Create a new user.
     - **Method**: `POST`
     - **Parameters**: 
       - `username`: The desired username.
- `email`: The email address of the user.
       - `password`: The desired password.
     - **Response**: 
       ```json
       {
        "id": 3,
        "username": "newuser",
"email": "newuser@example.com",
         "created_at": "2024-01-01T12:00:00Z"
       }
       ```
  
   - **/users/{id}** (PUT)
     - **Description**: Update details of a specific user.
     - **Method**: `PUT`
     - **Parameters**:
- `id`: The ID of the user.
       - `username`: The updated username.
       - `email`: Updated email address.
     - **Response**: 
       ```json
       {
"id": 1,
         "username": "updatedusername",
         "email": "updatedemail@example.com",
         "updated_at": "2024-01-01T12:30:00Z"
       }
       ```
**/users/{id}** (DELETE)
- **Description**: Deletes a single user by ID.
     - **Method**: `DELETE`
     - **Parameters**: 
       - `id`: The ID of the user.
     - **Response**: 
       ```json
       {
"message": "User deleted successfully."
      }
      ```
/**
2. **Content API**
   - **/content** (GET)
     - **Description**: Returns the list of all learning modules.
     - **Method**: `GET`
     - **Parameters**: None
     - **Response**:

    
```
    json
           [
            {
              "id": 1,
              "title": "Introduction to VR",
              "description": "Learn the basics of virtual reality.",
             },
    "created_at": "2024-01-01T12:00:00Z"
             },
             {
              "id": 2,
              "title": "Advanced VR Techniques",
    "description": "Create advanced VR content.",
              "created_at": "2024-01-02T14:00:00Z"
            }
          ]
```
  
  - **/content/{id}** (GET)
- **Description**: Get the details of a specific learning module by ID.
     - **Method**: `GET`
     - **Parameters**: 
       - `id`: The ID of the learning module.
     - **Response**: 
       ```json
       {
"id": 1,
        "title": "Introduction to VR",
        "description": "Learn the basics of virtual reality.",
        "created_at": "2024-01-01T12:00:00Z",
        "updated_at": "2024-01-01T12:30:00Z"
      }
```

   - **/content** (POST)
     - **Description**: Create a new learning module.
     - **Method**: `POST`
     - **Parameters**: 
       - `title`: The title of the learning module.
       - `description`: A brief description of the content.
```json
       {
         "id": 3,
         "title": "New VR Module",
         "description": "Learn about new VR technologies.",
         "created_at": "2024-01-03T12:00:00Z"}
}
       ```

   - **/content/{id}** (PUT)
     - **Description**: Update details of a specific learning module.
     - **Method**: `PUT`
     - **Parameters**: 
       - `id`: The ID of the learning module.
- `title`: The updated title (optional).
       - `description`: The updated description (optional).
     - **Response**:
       ```json
       {
         "id": 1,
         "title": "Updated VR Module",
"description": "Learn about the latest VR trends.",
         "updated_at": "2024-01-01T12:30:00Z"
       }
       ```

   - **/content/{id}** (DELETE)
     - **Description**: Delete a specific learning module by ID.
     - **Method**: `DELETE`
- **Parameters**: 
       - `id`: ID of the learning module.
     - **Response:**
       ```json
       {
         "message": "Learning module successfully deleted."
       }
```

### 3. **Interaction API**
   - **/interactions** (GET)
     - **Description**: Retrieve a list of all interactions (quizzes, simulations, etc.).
     - **Method**: `GET`
     - **Parameters**: None
     - **Response**: 
       ```json
       [
{
         "id": 1,
         "title": "Pendulum Simulation",
         "type": "simulation",
         "created_at": "2024-01-01T12:00:00Z"
       },
{
           "id": 2,
           "title": "VR Quiz on Physics",
           "type": "quiz",
           "created_at": "2024-01-02T14:00:00Z"
}
       ]
       ```

   - **/interactions/{id}** (GET)
     - **Description**: Retrieve details of a specific interaction by ID.
     - **Method**: `GET`
     - **Parameters**:
- `id`: The ID of the interaction.
     - **Response**: 
       ```json
       {
         "id": 1,
         "title": "Pendulum Simulation",
         "type": "simulation",
"created_at": "2024-01-01T12:00:00Z",
         "updated_at": "2024-01-01T12:30:00Z"
       }
       ```
/**
   - **/interactions** (POST)
     - **Description**: Create a new interaction (simulation, quiz, etc.).
     - **Method**: `POST`
     - **Parameters**:
- `title`: The title of the interaction.
       - `type`: The type of interaction (e.g., simulation, quiz).
       - `content`: The content of the interaction (e.g., questions, simulation parameters).
     - **Response**:
       ```json
       {
"id": 3,
         "title": "New VR Quiz",
         "type": "quiz",
         "created_at": "2024-01-03T12:00:00Z"
       }
       ```
  
   - **/interactions/{id}** (PUT)
- **Description**: Update information of an interaction.
     - **Method**: `PUT`
     - **Parameters**: 
       - `id`: The ID of the interaction.
       - `title`: The updated title.
       - `type`: The updated type.
- `content`: The updated content (optional).
     - **Response**: 
       ```json
       {
        "id": 1,
        "title": "Updated VR Quiz",
        "type": "quiz",
"updated_at": "2024-01-01

T12:30:00Z"
       }
       ```
   - **/interactions/{id}** (DELETE)
     - **Description**: Delete an interaction by ID.
     - **Method**: `DELETE`
     - **Parameters**: 
       - `id`: The ID of the interaction.
- **Response**: 
       ```json
       {
         "message": "Interaction successfully deleted."
       }
       ```

## Authentication

Authentication for all API requests is required. The following authentication methods are supported:

- **Bearer Token**: Pass a `Bearer` token in the `Authorization` header for all requests.
  - **Header**: `Authorization: Bearer [token]`
  - **Example**:
    ```http
    GET /users HTTP/1.1
    Host: api.vrlearningenvironment.com
    Authorization: Bearer abc123xyz
    ```

- **API Key**: Use an API key to authenticate requests.
  - **Header**: `X-API-KEY: [your-api-key]`
  - **Example**:
    ```http
GET /content HTTP/1.1
    Host: api.vrlearningenvironment.com
    X-API-KEY: 1234567890abcdef
    ```
    
## Error Handling

Errors will be returned in a standard JSON format:

```json
{
  "error": {
    "code": 400,
    "message": "Bad Request",
    "details": "The provided input data is not valid."
  }
}
```

- **Error Codes**:
- `400` - Bad Request: The request could not be understood or was missing required parameters.
  - `401` - Unauthorized: Authentication failed or user does not have permission for the requested operation.
  - `403` - Forbidden: The request is understood, but it has been refused or access is not allowed.
  - `404` - Not Found: The requested resource could not be found.
- `500` - Internal Server Error: An unexpected condition was encountered on the server.

## Example Requests and Responses

### Example Request: Create a New User
```http
POST /users HTTP/1.1
Host: api.vrlearningenvironment.com
Content-Type: application/json
{
  "username": "newuser",
  "email": "newuser@example.com",
  "password": "securepassword"
}
```

### Example Response:
```json
{
  "id": 3,
  "username": "newuser",
  "email": "newuser@example.com",
  "created_at": "2024-01-03T12:00:00Z"
}
```

### Example Request: Retrieve All Learning Modules
```http
GET /content HTTP/1.1
Host: api.vrlearningenvironment.com
```

### Example Response:
```json
[
  {
1,
    "title": "Introduction to VR",
    "description": "Learn the basics of virtual reality.",
    "created_at": "2024-01-01T12:00:00Z"
  },
  {
    "id": 2,
    "title": "Advanced VR Techniques",
    "description": "Explore advanced VR content creation.",
    "created_at": "2024-01-02T14:00:00Z"
  }
]
```

### Example Request: Update an Interaction
```http
PUT /interactions/1 HTTP/1.1
Host: api.vrlearningenvironment.com
Content-Type: application/json
```
"title": "Updated VR Simulation",
  "type": "simulation"
}
```

### Example Response:
```json
{
  "id": 1,
  "title": "Updated VR Simulation",
  "type": "simulation",
  "updated_at": "2024-01-01T12:30:00Z"
}
```

---
