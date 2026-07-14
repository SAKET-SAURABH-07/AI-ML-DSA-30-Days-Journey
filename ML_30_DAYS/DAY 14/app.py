import streamlit as st
import pandas as pd
import numpy as np

from sklearn.preprocessing import StandardScaler
from sklearn.cluster import KMeans
from sklearn.decomposition import PCA

import matplotlib.pyplot as plt
import seaborn as sns

st.set_page_config(page_title="FIFA K-Means Clustering", layout="wide")

st.title("⚽ FIFA World Cup 2026 K-Means Clustering Dashboard")

df = pd.read_csv("cleaned_fifa_dataset.csv")

numeric_df = df.select_dtypes(include=["int64","float64"])

st.sidebar.header("Settings")

selected_features = st.sidebar.multiselect(
    "Select Features",
    numeric_df.columns.tolist(),
    default=numeric_df.columns.tolist()
)

k = st.sidebar.slider(
    "Number of Clusters",
    min_value=2,
    max_value=10,
    value=3
)

X = numeric_df[selected_features]

scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

kmeans = KMeans(n_clusters=k, random_state=42, n_init=10)

clusters = kmeans.fit_predict(X_scaled)

df["Cluster"] = clusters

pca = PCA(n_components=2)
X_pca = pca.fit_transform(X_scaled)

pca_df = pd.DataFrame(X_pca, columns=["PC1","PC2"])
pca_df["Cluster"] = clusters

st.subheader("Cluster Visualization")

fig, ax = plt.subplots(figsize=(10,6))

sns.scatterplot(
    data=pca_df,
    x="PC1",
    y="PC2",
    hue="Cluster",
    palette="Set2",
    s=90,
    ax=ax
)

st.pyplot(fig)

st.subheader("Cluster Summary")

st.dataframe(df.groupby("Cluster").mean(numeric_only=True))

st.subheader("Cluster Counts")

st.bar_chart(df["Cluster"].value_counts().sort_index())

csv = df.to_csv(index=False)

st.download_button(
    "Download Clustered Dataset",
    csv,
    file_name="fifa_clustered.csv",
    mime="text/csv"
)