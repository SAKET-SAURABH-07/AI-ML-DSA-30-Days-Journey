import streamlit as st
import numpy as np
import pickle


# Load model and scaler

model = pickle.load(
    open("house_price_model.pkl", "rb")
)

scaler = pickle.load(
    open("scaler.pkl", "rb")
)


st.title("🏠 House Price Prediction")

st.write("Enter house details")


MedInc = st.slider(
    "Median Income",
    0.0,
    15.0,
    3.0
)

HouseAge = st.slider(
    "House Age",
    1,
    60,
    20
)

AveRooms = st.slider(
    "Average Rooms",
    1.0,
    20.0,
    5.0
)

AveBedrms = st.slider(
    "Average Bedrooms",
    0.5,
    10.0,
    1.0
)

Population = st.slider(
    "Population",
    100,
    5000,
    1000
)

AveOccup = st.slider(
    "Average Occupancy",
    1.0,
    10.0,
    3.0
)

Latitude = st.slider(
    "Latitude",
    32.0,
    42.0,
    35.0
)

Longitude = st.slider(
    "Longitude",
    -125.0,
    -114.0,
    -120.0
)


if st.button("Predict Price"):

    data = np.array(
        [[
            MedInc,
            HouseAge,
            AveRooms,
            AveBedrms,
            Population,
            AveOccup,
            Latitude,
            Longitude
        ]]
    )


    data_scaled = scaler.transform(data)


    prediction = model.predict(data_scaled)


    st.success(
        f"Predicted House Price: ${prediction[0]*100000:,.2f}"
    )